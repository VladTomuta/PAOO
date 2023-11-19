#include "lazyDog.h"
#include <string.h>
#include <iostream>

using namespace Shelter;

LazyDog::LazyDog(std::string name, int age, bool isTailWagging) : Dog(name, age, isTailWagging) {

}

LazyDog::~LazyDog() {

}

LazyDog::LazyDog(const LazyDog &lazyDog) : Dog(lazyDog) {

}

LazyDog::LazyDog(LazyDog &&lazyDog) : Dog(lazyDog){

}

LazyDog& LazyDog::operator= (const LazyDog &lazyDog) {
    if (this != &lazyDog) {
        delete[] this->name;

        this->name = new char[strlen(lazyDog.name) + 1];
        strcpy(name, lazyDog.name);
        this->age = lazyDog.age;
        this->isTailWagging = lazyDog.isTailWagging;

        std::cout << this->name << " has been copied using '=' --> overload for COPY CONSTRUCTOR.\n";
    }
    
    return *this;
}

LazyDog& LazyDog::operator=(LazyDog &&lazyDog) {
    if (this != &lazyDog) {
        delete[] this->name;

        this->name = lazyDog.name;
        this->age = lazyDog.age;
        this->isTailWagging = lazyDog.isTailWagging;

        lazyDog.name = nullptr;
        lazyDog.age = 0;
        lazyDog.isTailWagging = false;

        std::cout << this->name << " has been moved using '=' --> overload for MOVE CONSTRUCTOR.\n";
    }

    return *this;
}

void LazyDog::playFetch() const {
    std::cout << "The dog is too lazy to play fetch with you.\n";
}