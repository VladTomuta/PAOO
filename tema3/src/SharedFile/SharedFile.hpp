#include <string>
#include <mutex>
#include <fstream>
#include <memory>
#include "Semaphore.hpp"
#include "Message.hpp"

class SharedFile {
    public:
        SharedFile(std::string filename, std::shared_ptr<Semaphore> semaphore);
        void writeToFile(int id, Message message);
        void readFromFile(int id);
        void clearFileContent();
    private:
        std::mutex mutex;
        std::string filename;
        std::ofstream fileStream;
        std::shared_ptr<Semaphore> semaphore;
};