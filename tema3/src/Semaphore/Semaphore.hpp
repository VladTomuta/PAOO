#pragma once

#include <mutex>
#include <condition_variable>

class Semaphore {
    public:
        Semaphore();
        void wait();
        void signal();

    private:
        std::mutex mutex;
        std::condition_variable condition;
        bool isResourceUsed;
};