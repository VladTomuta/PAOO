using namespace std;
#include <string>

class Cat {
    private:
        char* name;
        int age;
        char* say;

    public:
        Cat(string name, int age, string say);
        ~Cat();
        Cat(const Cat &cat);
        Cat(Cat &&cat);

        void setName(string name);
        char* getName();

        void setAge(int age);
        int getAge();

        void setSay(string say);
        char* getSay();

        void meow();
};