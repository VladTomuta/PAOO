#include "Message.hpp"

Message::Message(std::string content) {
    this->content = content;
}

std::string Message::getContent() {
    return this->content;
}