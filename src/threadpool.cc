#include "threadpool.h"

threadpool::threadpool(int num_threads) {
    for (int i = 0; i < num_threads; i++)
        threads.push_back(std::thread(&threadpool::threadLoop, this));
}

void threadpool::threadLoop() {
    while (true) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            //also have to check should_terminate? - false initially
            mutex_condition.wait(lock, [this]{return should_terminate || !jobs.empty(); });
            //if should_terminate is true- thread should stop looking for a job
            if(should_terminate){
            	//decrement active thread
            	active_threads--; // do we decrement??
            	return; // it should return?
            }
            job = jobs.front();
            jobs.pop();
        }
	active_threads++; // add before the job
        job();
        active_threads--; //decrease after the job 
        
        //handling thread object destruction- join the threads for no zombies
        //if(active_threads == 0 && should_terminate) {
        	//for (std::thread& thread: threads){
        		//if the threads are joinable
        		//if(thread.joinable()){
        			//thread.join();
        		//}
        	//}
        //}
        
    }
}

//Kill the threads when threadpool object is destroyed
 threadpool::~threadpool() {
	stop();
}

void threadpool::queueJob(const std::function<void()>& job) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        jobs.push(job);
    }

    mutex_condition.notify_one();
}
void threadpool::start(){
	//set thread_terminate to fale
	should_terminate = false;
}
void threadpool::stop(){
	should_terminate = true;
	mutex_condition.notify_all(); //notify all threads about termination
	//handling thread object destruction- join the threads for no zombies
        if(active_threads == 0 && should_terminate) {
        	for (std::thread& thread: threads){
        		//if the threads are joinable
        		if(thread.joinable()){
        			thread.join();
        		}
        	}
        }
}
bool threadpool::busy(){
	return active_threads > 0;
}

