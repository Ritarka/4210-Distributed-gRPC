#pragma once
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>

class threadpool {
public:
    threadpool(int num_threads);
    ~threadpool();
    void queueJob(std::function<void()> job);

private:
    void threadLoop();

    bool should_terminate = false;           // Tells threads to stop looking for jobs
    std::mutex queue_mutex;                  // Prevents data races to the job queue
    std::condition_variable mutex_condition; // Allows threads to wait on new jobs or termination 
    std::condition_variable complete_condition; //for termination
    std::mutex complete_mutex;  //for termination
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> jobs;
    //count number of active threads - shared
    std::atomic<int> active_threads;
};

