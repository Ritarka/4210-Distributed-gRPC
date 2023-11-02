#pragma once
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>

class threadpool {
public:
    threadpool(int);
    bool available();
    void assign();
    int num_threads;
    int free;
    bool *threads_is_done;
};

