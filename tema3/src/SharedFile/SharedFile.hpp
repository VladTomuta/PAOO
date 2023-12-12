#pragma once

#include <string>
#include <mutex>
#include <fstream>
#include <memory>
#include "Semaphore.hpp"
#include "Message.hpp"
#include "Mutex.hpp"

class SharedFile {
    public:
        SharedFile(std::string filename, std::mutex& mutex);
        void writeToFile(int id, Message message);
        void readFromFile(int id);
        void clearFileContent();
    private:
        std::mutex& sharedMutex;
        std::string filename;
        std::ofstream fileStream;
        std::shared_ptr<Semaphore> semaphore;
};