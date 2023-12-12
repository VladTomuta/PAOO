#include "SharedFile.hpp"
#include <iostream>
#include <thread>
#include <chrono>

SharedFile::SharedFile(std::string filename, std::mutex &mutex) : sharedMutex(mutex) {
    this->filename = filename;
}

void SharedFile::writeToFile(int id, Message message) {
    Mutex mutex(this->sharedMutex);

    std::string data = "Thread " + std::to_string(id) + ":" + message.getContent();
    fileStream.open(filename, std::ios::app);
    fileStream << data << std::endl;
    fileStream.close();

    std::cout << "Thread " << id << " is going to sleep for 2 seconds\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " stopped sleeping\n";
}

void SharedFile::readFromFile(int id) {
    Mutex mutex(this->sharedMutex);

    std::ifstream inFile(filename, std::ios::in);
    std::string content;
    std::string line;
    while (std::getline(inFile, line)) {
        content += line + "\n";
    }
    inFile.close();

    std::cout << "Thread " << id << " is going to sleep for 2 seconds\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread " << id << " stopped sleeping\n";
    
    std::cout << "Thread " << id << ": Content of the file:\n" << content << std::endl;
}

void SharedFile::clearFileContent() {
    Mutex mutex(this->sharedMutex);

    fileStream.close();
    fileStream.open(filename, std::ofstream::out | std::ofstream::trunc);
    fileStream.close();
}
