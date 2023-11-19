#include "scaredCat.h"
#include <iostream>
#include <string.h>

using namespace Shelter;

ScaredCat::ScaredCat(std::string name, int age, std::string say) : Cat(name, age, say) {

}

ScaredCat::~ScaredCat() {

}

ScaredCat::ScaredCat(const ScaredCat &scaredCat) : Cat (scaredCat) {

}

ScaredCat::ScaredCat(ScaredCat &&scaredCat) : Cat(scaredCat){

}

ScaredCat& ScaredCat::operator= (const ScaredCat &scaredCat) {
    if (this != &scaredCat) {
        delete[] this->name;
        delete[] this->say;

        this->name = new char[strlen(scaredCat.name) + 1];
        strcpy(this->name, scaredCat.name);
        this->age = scaredCat.age;
        this->say = new char[strlen(scaredCat.say) + 1];
        strcpy(this->say, scaredCat.say);

        std::cout << this->name << " has been copied using '=' --> overload for COPY CONSTRUCTOR.\n";
    }
    
    return *this;
}

ScaredCat& ScaredCat::operator=(ScaredCat &&scaredCat) {
    if (this != &scaredCat) {
        delete[] this->name;
        delete[] this->say;

        this->name = scaredCat.name;
        this->age = scaredCat.age;
        this->say = scaredCat.say;

        scaredCat.name = nullptr;
        scaredCat.age = 0;
        scaredCat.say = nullptr;

        std::cout << this->name << " has been moved using '=' --> overload for MOVE CONSTRUCTOR.\n";
    }

    return *this;
}

void ScaredCat::rubBelly() const {
    std::cout << this->name <<" is scared of you so it doesn't let you to rub her belly.\n";
}