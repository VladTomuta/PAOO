#pragma once
#include <string>

namespace Shelter {
    class IAnimal {
    protected:
        char* name;
        int age;
    public:
        virtual void setName(std::string name) = 0;
        virtual char* getName() const = 0;
        virtual void setAge(int age) = 0;
        virtual int getAge() const = 0;

        virtual void speak() const = 0;
    };
}