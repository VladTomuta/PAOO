#include "cat.h"
#include <iostream>

using namespace std;

int main() {
    Cat kimi("Kimi", 5, "meeeeooow");
    Cat simba("Simba", 6, "purrrrrr");

    cout << "My cat's name is " << kimi.getName() << " and she is " << kimi.getAge() << " years old.\n";
    kimi.meow();

    Cat kimiCopy = kimi;

    cout << "My cat's (that has been copied) name is " << kimi.getName() << " and she is " << kimi.getAge() << " years old.\n";

    cout << "My other cat's name is " << simba.getName() << " and she is " << simba.getAge() << " years old.\n";
    simba.meow();

    Cat simbaMove(std::move(simba));

    cout << "My other cat's (that has been moved) name is " << simbaMove.getName() << " and she is " << simbaMove.getAge() << " years old.\n";
    simbaMove.meow();

    return 0;
}