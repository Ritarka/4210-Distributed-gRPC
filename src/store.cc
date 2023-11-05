#include <mutex>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include <iostream>

//#include "absl/strings/str_format.h"

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
//for asyn client
using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;

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
std::string server_ip; //server's ip address
int port; //parse ip_addr to get the port
int num_threads;

std::vector<std::string> vendor_addresses;
int free_threads;
std::vector<std::thread*> threads;

std::mutex q_mutex;

//threadpool& pool_;


class StoreSrv final {
 public:
 //initialize the threadpool
  StoreSrv(int num_threads)
  	: pool_(num_threads) {}
  ~StoreSrv() {
    //destroy threadpool when server shutsdown
    //pool_.stop();
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    cq_->Shutdown();
  }

  // There is no shutdown handling in this code.
  void run() {
    //std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
    std::string server_address = server_ip + std::to_string(port);
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
    //pool_.start();
    //for (int i = 0; i < num_threads; i++){
    	//pool_.queueJob([this](){ HandleRpcs(); });
    //}
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

        service_->RequestgetProducts(&ctx_, &request_, &responder_, cq_, cq_, this);
		
      } else if (status_ == PROCESS) {
        // Spawn a new CallData instance to serve new clients while we process
        // the one for this CallData. The instance will deallocate itself as
        // part of its FINISH state.
        new CallData(service_, cq_);

        std::unique_ptr<grpc::CompletionQueue> client_cq_(new grpc::CompletionQueue);

        std::vector<BidReply> replies(vendor_addresses.size());
        std::vector<Status> statuses(vendor_addresses.size());
        std::vector<std::unique_ptr<Vendor::Stub>> stubs(vendor_addresses.size());


        for (int i = 0; i < vendor_addresses.size(); i++) {
          std::string vendor_address_ = vendor_addresses[i];

          BidQuery vendor_request; //create a request to vendors
          // BidReply* vendor_reply = (BidReply*)malloc(sizeof(BidReply)); // create a response from vendors
          
          //grpc channel to vendor using vendor_address_
          std::shared_ptr<Channel> channel = grpc::CreateChannel(vendor_address_, grpc::InsecureChannelCredentials());
          stubs[i] = Vendor::NewStub(channel);
          // stubs.push_back(stubs);

          vendor_request.set_product_name(request_.product_name());
          
          //make the call to vendor
          grpc::ClientContext vendor_context;
          //client's completion queue
          //Status for client
          // Status* client_status = new Status();
          //this call needs to be async
          std::unique_ptr<ClientAsyncResponseReader<BidReply>>rpc(stubs[i]->AsyncgetProductBid(&vendor_context, vendor_request, client_cq_.get()));
          
          // Request that, upon completion of the RPC, "reply" be updated with the
          // server's response; "status" with the indication of whether the operation
          // was successful. Tag the request with the integer 1.
          rpc->Finish(&replies[i], &statuses[i], (void*)i);

          // void* client_got_tag;
          // bool client_ok = false;

          // GPR_ASSERT(client_cq_->Next(&client_got_tag, &client_ok));
          // GPR_ASSERT(client_ok);

          // int index = *((int*)(&client_got_tag));
          // std::cout << index << std::endl;

          // //process vendor response
          // if(statuses[index].ok()){
          // 	ProductInfo* product_info = reply_.add_products();
          // 	product_info->set_vendor_id(replies[index].vendor_id());
          // 	product_info->set_price(replies[index].price());
          // }

        }

        for (int i = 0; i < vendor_addresses.size(); i++) {
          void* client_got_tag;
          bool client_ok = false;

          GPR_ASSERT(client_cq_->Next(&client_got_tag, &client_ok));
          GPR_ASSERT(client_ok);

          int index = *((int*)(&client_got_tag));
          // std::cout << index << std::endl;

          //process vendor response
          if(statuses[index].ok()){
          	ProductInfo* product_info = reply_.add_products();
          	product_info->set_vendor_id(replies[index].vendor_id());
          	product_info->set_price(replies[index].price());
          }
        }
        // std::cout << "We are done" << std::endl;
        // And we are done! Let the gRPC runtime know we've finished
        status_ = FINISH;
        responder_.Finish(reply_, Status::OK, this);
      } else {
        GPR_ASSERT(status_ == FINISH);
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
      //std::unique_lock<std::mutex> q_lock(q_mutex);
      GPR_ASSERT(cq_->Next(&tag, &ok));
     // q_lock.unlock(); // release the mutex
      GPR_ASSERT(ok);
      pool_.queueJob([this, tag](){ static_cast<CallData*>(tag)->Proceed(); });
      // static_cast<CallData*>(tag)->Proceed();

    }


  }

  std::unique_ptr<ServerCompletionQueue> cq_;
  Store::AsyncService service_;
  std::unique_ptr<Server> server_;
  //thread pool
  threadpool pool_;
  
};

int main(int argc, char** argv) {
  
  addr_path = argv[1];
  ip_addr = argv[2];
  num_threads = atoi(argv[3]);

  //threadpool pool(num_threads);

  //find the last occurence of :
  size_t colon_pos = ip_addr.find_last_of(':');
  if(colon_pos != std::string::npos){
  	//extract the port number
  	server_ip = ip_addr.substr(0, colon_pos + 1);
  	//server_ip = "0.0.0.0:";
  	std::cout << "IP: " << server_ip << std::endl;
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

  // std::fill_n(threads, num_threads, NULL);
  //free_threads = num_threads;

  //pool_ = new threadpool(num_threads);

  StoreSrv store(num_threads);
  //StoreSrv store;
  store.run();

  //delete pool;
  
  return 0;
}