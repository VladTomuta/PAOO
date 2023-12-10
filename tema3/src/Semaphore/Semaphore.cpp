#include "Semaphore.hpp"

Semaphore::Semaphore() {
    this->isResourceUsed = false;
}

void Semaphore::wait() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [this] { return isResourceUsed == false; });
    isResourceUsed = true;
}

void Semaphore::signal() {
    std::unique_lock<std::mutex> lock(mutex);
    isResourceUsed = false;
    condition.notify_one();
}