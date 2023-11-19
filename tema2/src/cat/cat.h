#pragma once
#include "animal.h"
#include <string>

namespace Shelter {
    class Cat : public IAnimal{
        protected:
            char* say;

        public:
            Cat(std::string name, int age, std::string say);
            ~Cat();
            Cat(const Cat &cat);
            Cat(Cat &&cat);

            Cat& operator=(const Cat &cat);
            Cat& operator=(Cat &&cat);

            void setName(std::string name);
            char* getName() const;
            void setAge(int age);
            int getAge() const;
            void setSay(std::string say);
            char* getSay() const;

            void speak() const;
            virtual void rubBelly() const;
    };
}
