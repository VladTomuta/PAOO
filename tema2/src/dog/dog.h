#pragma once
#include "animal.h"
#include <string>

namespace Shelter {
    class Dog: public IAnimal {
        protected:
            bool isTailWagging;
        public:
            Dog(std::string name, int age, bool isTailWagging);
            ~Dog();
            Dog(const Dog &dog);
            Dog(Dog &&dog);

            Dog& operator=(const Dog &dog);
            Dog& operator=(Dog &&dog);

            char* getName() const;
            void setName(std::string name);
            int getAge() const;
            void setAge(int age);
            bool getIsTailWagging() const;
            void setIsTailWagging(bool isTailWagging);

            void speak() const;
            virtual void playFetch() const;
    };
}