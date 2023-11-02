#pragma once

class threadpool {
public:
    threadpool(int);
    bool available();
    void assign();
    int num_threads;
    int free;
    bool *threads_is_done;
};

