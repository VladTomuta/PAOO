#include "cat.h"
#include <cstring>
#include <iostream>

Cat::Cat(string name, int age, string say) {
    this->name = new char[name.length() + 1];
    strcpy(this->name, name.c_str());

    this->age = age;

    this->say = new char[say.length() + 1];
    strcpy(this->say, say.c_str());

    cout << this->name << " has been created inside the NORMAL CONSTRUCTOR!\n";
}

Cat::~Cat() {

    if(this->name != nullptr)
        cout << this->name << " has been DESTRUCTED!\n";
    else
        cout << "nullptr has been DESTRUCTED!\n";

    delete[] name;
    delete[] say;
}

Cat::Cat(const Cat &cat) {
    this->name = new char[strlen(cat.name) + 1];
    strcpy(name, cat.name);

    this->age = cat.age;

    this->say = new char[strlen(cat.say) + 1];
    strcpy(say, cat.say);

    cout << this->name << " has been copied inside the COPY CONSTRUCTOR!\n";
}

Cat::Cat(Cat &&cat) {
    this->name = new char[strlen(cat.name) + 1];
    strcpy(name, cat.name);

    this->age = cat.age;

    this->say = new char[strlen(cat.say) + 1];
    strcpy(say, cat.say);

    cat.name = nullptr;
    cat.say = nullptr;

    cout << this->name << " has been moved inside the MOVE CONSTRUCTOR!\n";
}

void Cat::setName(string name) {
    strcpy(this->name, name.c_str());
}

char* Cat::getName() {
    return name;
}

void Cat::setAge(int age) {
    this->age = age;
}

int Cat::getAge() {
    return age;
}

void Cat::setSay(string say) {
    strcpy(this->say, say.c_str());
}

char* Cat::getSay() {
    return say;
}

void Cat::meow() {
    std::cout << name << " says: " << say << "!" << std::endl;
}
