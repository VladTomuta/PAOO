#include "playfulDog.h"
#include <string.h>
#include <iostream>

using namespace Shelter;

PlayfulDog::PlayfulDog(std::string name, int age, bool isTailWagging) : Dog(name, age, isTailWagging) {

}

PlayfulDog::~PlayfulDog() {

}

PlayfulDog::PlayfulDog(const PlayfulDog &playfulDog) : Dog (playfulDog) {

}

PlayfulDog::PlayfulDog(PlayfulDog &&playfulDog) : Dog(playfulDog){

}

PlayfulDog& PlayfulDog::operator= (const PlayfulDog &playfulDog) {
    if (this != &playfulDog) {
        delete[] this->name;

        this->name = new char[strlen(playfulDog.name) + 1];
        strcpy(name, playfulDog.name);
        this->age = playfulDog.age;
        this->isTailWagging = playfulDog.isTailWagging;

        std::cout << "\n" << this->name << " has been copied using '=' --> overload for COPY CONSTRUCTOR.\n";
    }
    
    return *this;
}

PlayfulDog& PlayfulDog::operator=(PlayfulDog &&playfulDog) {
    if (this != &playfulDog) {
        delete[] this->name;

        this->name = playfulDog.name;
        this->age = playfulDog.age;
        this->isTailWagging = playfulDog.isTailWagging;

        playfulDog.name = nullptr;
        playfulDog.age = 0;
        playfulDog.isTailWagging = false;

        std::cout << this->name << " has been moved using '=' --> overload for MOVE CONSTRUCTOR.\n";
    }

    return *this;
}

void PlayfulDog::playFetch() const {
    std::cout << "The dog is playful, so it plays fetch with you.\n";
}