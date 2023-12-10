#include "SharedFile.hpp"
#include <iostream>

SharedFile::SharedFile(std::string filename, std::shared_ptr<Semaphore> semaphore) {
    this->filename = filename;
    this->semaphore = semaphore;
}

void SharedFile::writeToFile(int id) {
    semaphore->wait();

    std::unique_lock<std::mutex> lock(mutex);

    std::string data = "Thread " + std::to_string(id) + ": Hello this is the thread with id " + std::to_string(id);
    fileStream.open(filename, std::ios::app);
    fileStream << data << std::endl;
    fileStream.close();

    lock.unlock();
    semaphore->signal();
}

void SharedFile::readFromFile(int id) {
    semaphore->wait();

    std::unique_lock<std::mutex> lock(mutex);

    std::ifstream inFile(filename, std::ios::in);
    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line + "\n";
    }
    inFile.close();

    lock.unlock();
    semaphore->signal();
    
    std::cout << "Thread " << id << ": Content of the file:\n" << content << std::endl;
}

void SharedFile::clearFileContent() {
    semaphore->wait();
    std::unique_lock<std::mutex> lock(mutex);
    fileStream.close();
    fileStream.open(filename, std::ofstream::out | std::ofstream::trunc);
    fileStream.close();
    semaphore->signal();
}
