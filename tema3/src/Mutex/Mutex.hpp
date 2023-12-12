#pragma once

#include <mutex>

class Mutex {
public:
    Mutex(std::mutex& mutex);
    ~Mutex();

private:
    std::mutex& mutex;
};