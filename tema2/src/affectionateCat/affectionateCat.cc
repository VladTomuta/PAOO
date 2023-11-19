#include "affectionateCat.h"
#include <iostream>
#include <string.h>

using namespace Shelter;

AffectionateCat::AffectionateCat(std::string name, int age, std::string say) : Cat(name, age, say) {

}

AffectionateCat::~AffectionateCat() {

}

AffectionateCat::AffectionateCat(const AffectionateCat &affectionateCat) : Cat(affectionateCat) {

}

AffectionateCat::AffectionateCat(AffectionateCat &&affectionateCat) : Cat(affectionateCat){

}

AffectionateCat& AffectionateCat::operator= (const AffectionateCat &affectionateCat) {
    if (this != &affectionateCat) {
        delete[] this->name;
        delete[] this->say;

        this->name = new char[strlen(affectionateCat.name) + 1];
        strcpy(this->name, affectionateCat.name);
        this->age = affectionateCat.age;
        this->say = new char[strlen(affectionateCat.say) + 1];
        strcpy(this->say, affectionateCat.say);

        std::cout << this->name << " has been copied using '=' --> overload for COPY CONSTRUCTOR.\n";
    }
    
    return *this;
}

AffectionateCat& AffectionateCat::operator=(AffectionateCat &&affectionateCat) {
    if (this != &affectionateCat) {
        delete[] this->name;
        delete[] this->say;

        this->name = affectionateCat.name;
        this->age = affectionateCat.age;
        this->say = affectionateCat.say;

        affectionateCat.name = nullptr;
        affectionateCat.age = 0;
        affectionateCat.say = nullptr;

        std::cout << this->name << " has been moved using '=' --> overload for MOVE CONSTRUCTOR.\n";
    }

    return *this;
}

void AffectionateCat::rubBelly() const {
    std::cout << this->name <<" likes you so it let's you to rub her belly.\n";
}