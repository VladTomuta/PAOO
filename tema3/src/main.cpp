#include <thread>
#include <memory>
#include "Semaphore.hpp"
#include "SharedFile.hpp"

int main() {
    const std::string filename = "shared_file.txt";
    std::shared_ptr<Semaphore> semaphore = std::make_shared<Semaphore>();
    std::shared_ptr<SharedFile> sharedFile = std::make_shared<SharedFile>(filename, semaphore);

    std::thread eraserThread1(&SharedFile::clearFileContent, sharedFile);
    eraserThread1.join();

    std::thread writerThread1(&SharedFile::writeToFile, sharedFile, 1);
    std::thread readerThread1(&SharedFile::readFromFile, sharedFile, 2);

    writerThread1.join();
    readerThread1.join();

    std::thread writerThread2(&SharedFile::writeToFile, sharedFile, 3);
    std::thread readerThread2(&SharedFile::readFromFile, sharedFile, 4);

    writerThread2.join();
    readerThread2.join();

    return 0;
}
