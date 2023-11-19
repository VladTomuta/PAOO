#include "dog.h"
#include <string.h>
#include <iostream>

using namespace Shelter;

Dog::Dog(std::string name, int age, bool isTailWagging) {
    this->name = new char(name.length() + 1);
    strcpy(this->name, name.c_str());
    this->age = age;
    this->isTailWagging = isTailWagging;

    std::cout << this->name << " has been created inside a CONSTRUCTOR.\n";
}

Dog::~Dog() {
    std::cout << "A dog has been DESTRUCTED.\n";

    delete[] name;
}

Dog::Dog(const Dog &dog) {
    this->name = new char(strlen(dog.name) + 1);
    strcpy(this->name, dog.name);
    this->age = dog.age;
    this->isTailWagging = dog.isTailWagging;

    std::cout << this->name << " has been created inside a COPY CONSTRUCTOR.\n";
}

Dog::Dog(Dog &&dog) {
    this->name = dog.name;
    this->age = dog.age;
    this->isTailWagging = dog.isTailWagging;

    dog.name = nullptr;
    dog.age = 0;
    dog.isTailWagging = false;

    std::cout << this->name << " has been created inside a MOVE CONSTRUCTOR.\n";
}

Dog& Dog::operator= (const Dog &dog) {
    if (this != &dog) {
        delete[] this->name;

        this->name = new char[strlen(dog.name) + 1];
        strcpy(this->name, dog.name);
        this->age = dog.age;
        this->isTailWagging = dog.isTailWagging;

        std::cout << this->name << " has been copied using '=' --> overload for COPY CONSTRUCTOR.\n";
    }
    
    return *this;
}

Dog& Dog::operator=(Dog &&dog) {
    if (this != &dog) {
        delete[] this->name;

        this->name = dog.name;
        this->age = dog.age;
        this->isTailWagging = dog.isTailWagging;

        dog.name = nullptr;
        dog.age = 0;
        dog.isTailWagging = false;

        std::cout << this->name << " has been moved using '=' --> overload for MOVE CONSTRUCTOR.\n";
    }

    return *this;
}

char* Dog::getName() const {
    return this->name;
}

void Dog::setName(std::string name) {
    delete[] this->name;
    this->name = new char(name.length() + 1);
}

int Dog::getAge() const {
    return this->age;
}

void Dog::setAge(int age) {
    this->age = age;
}

bool Dog::getIsTailWagging() const {
    return this->isTailWagging;
}

void Dog::setIsTailWagging(bool isTailWagging) {
    this->isTailWagging = isTailWagging;
}

void Dog::speak() const {
    std::cout << this->name << " says: bark bark bark.\n";
}

void Dog::playFetch() const {
    std::cout << "You are playing fetch with " << this->name << std::endl;
}