#pragma once

#include <string>

class Message {
    public:
        Message(std::string content);
        std::string getContent();
    private:
        std::string content;
};