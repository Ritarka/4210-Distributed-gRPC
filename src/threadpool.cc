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
            mutex_condition.wait(lock, [this]{return !jobs.empty(); });
            job = jobs.front();
            jobs.pop();
        }

        job();
    }
}

void threadpool::queueJob(const std::function<void()>& job) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        jobs.push(job);
    }

    mutex_condition.notify_one();
}


