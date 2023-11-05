#include "threadpool.h"

threadpool::threadpool(int num_threads) {
    for (int i = 0; i < num_threads; i++)
        threads.push_back(std::thread(&threadpool::threadLoop, this));
        ++active_threads;
}

void threadpool::threadLoop() {
    while (true) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            //also have to check should_terminate? - false initially
            mutex_condition.wait(lock, [this]{return should_terminate || !jobs.empty(); });
            if (should_terminate)
            	return;
            
            job = jobs.front();
            jobs.pop();
        }
        job();
        {
        	--active_threads;
        	if(should_terminate && active_threads == 0){
        		complete_condition.notify_all();
        	}
        }       
        
    }
}

//Kill the threads when threadpool object is destroyed
 threadpool::~threadpool() {
	//will unlock after the block
	{
		std::unique_lock<std::mutex> lock(queue_mutex);
		should_terminate = true;
	}
	
	mutex_condition.notify_all();
	{
		std::unique_lock<std::mutex> lock(complete_mutex);
		complete_condition.wait(lock, [this] {return active_threads == 0;});
	}
	//join threads
	for(std::thread& thread: threads){
		thread.join();
	}
}

void threadpool::queueJob(std::function<void()> job) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        //debugging purpose
        if(should_terminate){
        	throw std::runtime_error("Threadpool stopped at enqueue");
        }
        jobs.push(job);
    }

    mutex_condition.notify_one();
}

