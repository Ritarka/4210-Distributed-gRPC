#pragma once
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>

class threadpool{

public:
	threadpool(size_t numThreads);
	~threadpool();
	
	//template <class F, class... Args>
	void enqueue(std::function<void(void)> func);
	void wait();
private:
	size_t numThreads_;
	std::vector<std::thread> threads_;
	std::queue<std::function<void()>> tasks_;
	std::mutex queueMutex_;
	std::condition_variable cv_;
	std::atomic<bool> stop_;
	
	void workerThread();
	
};

