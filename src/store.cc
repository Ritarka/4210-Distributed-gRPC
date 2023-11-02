#include <mutex>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include <iostream>

#include "absl/strings/str_format.h"

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>

#include "../external/protos/store.grpc.pb.h"
#include "../external/protos/vendor.grpc.pb.h"
#include "threadpool.h"


using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

using store::Store;
using store::ProductQuery;
using store::ProductReply;
using store::ProductInfo;

//add the vendors definitions
using vendor::Vendor;
using vendor::BidQuery;
using vendor::BidReply;

std::string addr_path;
std::string ip_addr; // for command line
int port; //parse ip_addr to get the port
int num_threads;
std::vector<std::string> vendor_addresses;

std::mutex q_mutex;

threadpool::threadpool(int num_threads) : num_threads(num_threads) {
  printf("Creating threadpool with %d threads\n", num_threads);
  free = num_threads;
  
  threads_is_done = new bool[num_max_threads];
  std::fill_n(threads_is_done, num_max_threads, false);
  std::vector<std::thread*> threads(num_max_threads, NULL);

  for (int i = 0; i < num_max_threads; ++i) {
    threads[i] = new std::thread(warm_up, std::ref(threads_is_done[i]));
  }
  
  std::vector<ProductQueryResult> test_results(product_specs.size());

  size_t thread_ind = 0;
  for (int i = 0; i < product_specs.size(); ++i) {
    while (!threads_is_done[thread_ind]) {
      thread_ind = (thread_ind + 1) % num_max_threads;
    }
    
    threads[thread_ind]->join();
    delete threads[thread_ind];
    
    threads[thread_ind] = new std::thread(thread_task, 
          server_addr, std::ref(product_specs[i]), std::ref(test_results[i]), i, std::ref(threads_is_done[i]));
    
    thread_ind = (thread_ind + 1) % num_max_threads;
  }

  for (int i = 0; i < num_max_threads; ++i) {
    threads[i]->join();
  }
  delete threads_is_done;
}

bool threadpool::available() {
  return free > 0;
}

void threadpool::assign() {
  ;
}



class StoreSrv final {
 public:
  ~StoreSrv() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    cq_->Shutdown();
  }

  // There is no shutdown handling in this code.
  void run() {
    std::string server_address = absl::StrFormat("0.0.0.0:%d", port);

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service_" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&service_);
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    cq_ = builder.AddCompletionQueue();
    // Finally assemble the server.
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;

    // Proceed to the server's main loop.
    // Add the threadpool threads here, each thread will call HandleRpcs
    
    HandleRpcs();
    
    
  }

 private:
  // Class encompasing the state and logic needed to serve a request.
  class CallData {
   public:
    // Take in the "service" instance (in this case representing an asynchronous
    // server) and the completion queue "cq" used for asynchronous communication
    // with the gRPC runtime.
    CallData(Store::AsyncService* service, ServerCompletionQueue* cq)
        : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {

      // Invoke the serving logic right away.
      Proceed();
    }

    void Proceed() {
      if (status_ == CREATE) {
        // Make this instance progress to the PROCESS state.
        status_ = PROCESS;

        // As part of the initial CREATE state, we *request* that the system
        // start processing SayHello requests. In this request, "this" acts are
        // the tag uniquely identifying the request (so that different CallData
        // instances can serve different requests concurrently), in this case
        // the memory address of this CallData instance.
        service_->RequestgetProducts(&ctx_, &request_, &responder_, cq_, cq_, this);
		
      } else if (status_ == PROCESS) {
        // Spawn a new CallData instance to serve new clients while we process
        // the one for this CallData. The instance will deallocate itself as
        // part of its FINISH state.
        new CallData(service_, cq_);


        for (std::string vendor_address_ : vendor_addresses) {
          // The actual processing.
          //no thread support right now
          //make asyn rpc call to vendors
          BidQuery vendor_request; //create a request to vendors
          BidReply vendor_reply; // create a response from vendors
          
          //grpc channel to vendor using vendor_address_
          std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(vendor_address_, grpc::InsecureChannelCredentials());
          std::unique_ptr<Vendor::Stub> vendor_stub = Vendor::NewStub(channel);
          
          //make the call to vendor
          grpc::ClientContext vendor_context;
          vendor_stub->getProductBid(&vendor_context, vendor_request, &vendor_reply);
          
          //process vendor response
          //ProductReply reply; //reply_ defined in private
          ProductInfo* product_info = reply_.add_products();
          product_info->set_vendor_id(vendor_reply.vendor_id());
          product_info->set_price(vendor_reply.price());
        }
        
        // And we are done! Let the gRPC runtime know we've finished, using the
        // memory address of this instance as the uniquely identifying tag for
        // the event.
        status_ = FINISH;
        responder_.Finish(reply_, Status::OK, this);
      } else {
        GPR_ASSERT(status_ == FINISH);
        // Once in the FINISH state, deallocate ourselves (CallData).
        delete this;
      }
    }

   private:
    // The means of communication with the gRPC runtime for an asynchronous
    // server.
    Store::AsyncService* service_;
    // The producer-consumer queue where for asynchronous server notifications.
    ServerCompletionQueue* cq_;
    // Context for the rpc, allowing to tweak aspects of it such as the use
    // of compression, authentication, as well as to send metadata back to the
    // client.
    ServerContext ctx_;

    // What we get from the client.
    ProductQuery request_;
    // What we send back to the client.
    ProductReply reply_;

    // The means to get back to the client.
    ServerAsyncResponseWriter<ProductReply> responder_;
  
    // Let's implement a tiny state machine with the following states.
    enum CallStatus { CREATE, PROCESS, FINISH };
    CallStatus status_;  // The current serving state.
  };

  // This can be run in multiple threads if needed.
  void HandleRpcs() {
    // Spawn a new CallData instance to serve new clients.

    new CallData(&service_, cq_.get());

    void* tag;  // uniquely identifies a request.
    bool ok;

    while (true) {
      // Block waiting to read the next event from the completion queue. The
      // event is uniquely identified by its tag, which in this case is the
      // memory address of a CallData instance.
      // The return value of Next should always be checked. This return value
      // tells us whether there is any kind of event or cq_ is shutting down.
      GPR_ASSERT(cq_->Next(&tag, &ok));
      GPR_ASSERT(ok);
      static_cast<CallData*>(tag)->Proceed();
    }
  }

  std::unique_ptr<ServerCompletionQueue> cq_;
  Store::AsyncService service_;
  std::unique_ptr<Server> server_;
};


int main(int argc, char** argv) {
  
  addr_path = argv[1];
  ip_addr = argv[2];
  num_threads = atoi(argv[3]);

  threadpool pool(num_threads);

  //find the last occurence of :
  size_t colon_pos = ip_addr.find_last_of(':');
  if(colon_pos != std::string::npos){
  	//extract the port number
  	std::string port_str = ip_addr.substr(colon_pos + 1);
  	port = atoi(port_str.c_str());
  	std::cout << "Port: " << port << std::endl;
  }

  std::ifstream addr_file("vendor_addresses.txt");
  std::string line;
  //getting the addresses from the file
  while(std::getline(addr_file, line)) {
    vendor_addresses.push_back(line);
    std::cout << line << std::endl;
  }

  StoreSrv store;
  store.run();
  return 0;
}