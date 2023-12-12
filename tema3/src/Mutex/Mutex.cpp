#include "Mutex.hpp"

Mutex::Mutex(std::mutex &sharedMutex) : mutex(sharedMutex) {
    mutex.lock();
}

Mutex::~Mutex() {
    mutex.unlock();
}