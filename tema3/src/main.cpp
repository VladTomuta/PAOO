#include <thread>
#include <memory>
#include "Semaphore.hpp"
#include "SharedFile.hpp"

int main() {
    const std::string filename = "shared_file.txt";
    std::shared_ptr<Semaphore> semaphore = std::make_shared<Semaphore>();
    std::shared_ptr<SharedFile> sharedFile = std::make_shared<SharedFile>(filename, semaphore);

    std::unique_ptr<Message> message1 = std::make_unique<Message>("Hey this is the message for writerThread1");
    std::unique_ptr<Message> message2 = std::make_unique<Message>("Hey this is the message for writerThread2");

    std::thread eraserThread1(&SharedFile::clearFileContent, sharedFile);
    eraserThread1.join();

    std::thread writerThread1(&SharedFile::writeToFile, sharedFile, 1, std::move(*message1));
    std::thread readerThread1(&SharedFile::readFromFile, sharedFile, 2);

    writerThread1.join();
    readerThread1.join();

    std::thread writerThread2(&SharedFile::writeToFile, sharedFile, 3, std::move(*message2));
    std::thread readerThread2(&SharedFile::readFromFile, sharedFile, 4);

    writerThread2.join();
    readerThread2.join();

    return 0;
}
