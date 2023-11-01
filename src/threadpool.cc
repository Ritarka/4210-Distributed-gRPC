#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>

class threadpool {
public:
	threadpool(size_t numThreads)
		: numThreads_(numThreads), stop_(false) {
		//Add threads to our threadpool
		for(size_t i = 0; i < numThreads_; i++) {
			threads_.emplace_back(std::bind(&threadpool::workerThread, this));
		}
	}
	~threadpool(){
		stop_ = true;
		cv_.notify_all();
		for(std::thread& thread: threads_){
			thread.join();
		}
	}
	
	template <class F, class... Args>
	void enqueue(F&& f, Args&&... args) {
		{
			std::unique_lock<std::mutex> lock(queueMutex_);
			tasks_.emplace(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
		}
		cv_.notify_one();
	}
private:
	size_t numThreads_;
	std::vector<std::thread> threads_;
	std::queue<std::function<void()>> tasks_;
	std::mutex queueMutex_;
	std::condition_variable cv_;
	std::atomic<bool> stop_;
	
	void workerThread(){
		while(!stop_){
			std::function<void()> task;
			{
				std::unique_lock<std::mutex> lock(queueMutex_);
				cv_.wait(lock, [this] {return stop_ || !tasks_.empty();});
				if(tasks_.empty()){
					continue;
				}
				task = std::move(tasks_.front());
				tasks_.pop();
			}
			if(task){
			
				task();
			}
		}
	}
};
	
