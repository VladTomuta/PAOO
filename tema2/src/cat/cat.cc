#include "cat.h"
#include <string.h>
#include <iostream>

using namespace Shelter;

Cat::Cat(std::string name, int age, std::string say) {
    this->name = new char[name.length() + 1];
    strcpy(this->name, name.c_str());

    this->age = age;

    this->say = new char[say.length() + 1];
    strcpy(this->say, say.c_str());

    std::cout << this->name << " has been created inside the CONSTRUCTOR.\n";
}

Cat::~Cat() {
    std::cout << "A cat has been DESTRUCTED.\n";

    delete[] name;
    delete[] say;
}

Cat::Cat(const Cat &cat) {
    this->name = new char[strlen(cat.name) + 1];
    strcpy(name, cat.name);

    this->age = cat.age;

    this->say = new char[strlen(cat.say) + 1];
    strcpy(say, cat.say);

    std::cout << this->name << " has been copied inside the COPY CONSTRUCTOR.\n";
}

Cat::Cat(Cat &&cat) {
    this->name = new char[strlen(cat.name) + 1];
    strcpy(name, cat.name);

    this->age = cat.age;

    this->say = new char[strlen(cat.say) + 1];
    strcpy(say, cat.say);

    cat.name = nullptr;
    cat.say = nullptr;

    std::cout << this->name << " has been moved inside the MOVE CONSTRUCTOR.\n";
}

Cat& Cat::operator= (const Cat &cat) {
    if (this != &cat) {
        delete[] this->name;
        delete[] this->say;

        this->name = new char[strlen(cat.name) + 1];
        strcpy(this->name, cat.name);
        this->age = cat.age;
        this->say = new char[strlen(cat.say) + 1];
        strcpy(this->say, cat.say);

        std::cout << this->name << " has been copied using '=' --> overload for COPY CONSTRUCTOR.\n";
    }
    
    return *this;
}

Cat& Cat::operator=(Cat &&cat) {
    if (this != &cat) {
        delete[] this->name;
        delete[] this->say;

        this->name = cat.name;
        this->age = cat.age;
        this->say = cat.say;

        cat.name = nullptr;
        cat.age = 0;
        cat.say = nullptr;

        std::cout << this->name << " has been moved using '=' --> overload for MOVE CONSTRUCTOR.\n";
    }

    return *this;
}

void Cat::setName(std::string name) {
    strcpy(this->name, name.c_str());
}

char* Cat::getName() const {
    return name;
}

void Cat::setAge(int age) {
    this->age = age;
}

int Cat::getAge() const {
    return age;
}

void Cat::setSay(std::string say) {
    strcpy(this->say, say.c_str());
}

char* Cat::getSay() const {
    return say;
}

void Cat::speak() const {
    std::cout << name << " says: " << say << ".\n";
}

void Cat::rubBelly() const {
    std::cout << "You are rubbing " << this->name <<"'s belly.\n";
}