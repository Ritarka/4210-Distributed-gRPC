Handling Asynchronous Client
* Our store acts as an asynchronous client to talk to vendor.cc and aggregates bids from all the vendor addresses that are mentioned in the vendor_addresses.txt file.
* We are using the grpc public member functions- Channel, ClientAsyncResponseReader, ClientContext, and Completion Queue. And from the vendor.cc we are using Vendor, BidQuery and BidReply members.
* In the main function, we are going through the vendor addresses file and adding all those addresses to a vector. And inside the proceed() function we are looping through that vector, and for each vendor address we are creating a grpc channel and a vendor_stub. Then we make the asynchronous call to the getProductBid, passing in the context, request and completion queue. 
* Then we ask for the reply, status and a unique tag, then we block until the next result is available in the completion queue, by checking the next tag returned. 
* Now if the status is okay then we add our vendor_reply to the async server reply (the final reply that goes to the client) and we set the vendor id and price according to the vendor reply. This is how our store performs as an async client to query product information from the vendors for the clients.
Handling Asynchronous Server
* Our store acts as an asynchronous server to handle connections from client.cc, and it returns the aggregated bid to our clients.
*  We are using some grpc asynchronous server members and we have the store members from the store's proto file.
* Similar to the example grpc code, we have a server class which has a HandleRpcsand run functions, and it has private CallData class, that contain- Calldata, proceed functions.
* In the public store server class we have a destructor code that shutdowns the server and the server completion queue.
* In the run function, we are setting up the server, the completion queue, and starting to listen on the server address passed in the command line arguments. And lastly we call the HandleRpcs function.
* Inside the HandleRpcs function, we create a new CallData instance for new clients, and then while true we make a blocking call to read the next event/ tag from the completion queue. And then we call the Proceed method of the CallData instance we created.
* In the Proceed function, we are checking the state/status of the CallState “state machine”. Depending on the states we perform different operations and change the state after it’s done. It is in the PROCESS state where we have our async client functionality. This is where we get bids from different vendors about our products and those bids are added to our async server reply.
* And we finish by sending the reply back to the client and delete our CallData instance.
Exposed APIs 
* We are exposing the following functions/members of store and vendors
* From vendor proto:
   * We are using BidQuery message to create a request to the vendor and BidReply message to create a response from the vendor
   * And are calling getProductBid asynchronously (AysngetProductBid) using BidQuery and getting a BidReply in return
* From Store proto:
   * We are using the ProductInfo message instance that would store our bid information. On the BidReply, we use .price() to get the price and .vendor_id() to get the vendor id
   * We are setting the price and vendor_id of the ProductInfo instance using set_price() and set_vendor_id() respectively
Threadpool Implementation
Citations:
* We used the boiler plate code of async server and async client from gRPC example code, and made modifications so that it works for our implementation.
* https://github.com/grpc/grpc/blob/v1.58.0/examples/cpp/helloworld/greeter_async_client.cc
* https://github.com/grpc/grpc/blob/v1.58.0/examples/cpp/helloworld/greeter_async_server.cc
* https://grpc.io/docs/languages/cpp/async/
* We also used the site below to assist with out threadpool implementation
* https://stackoverflow.com/questions/15752659/thread-pooling-in-c11