#include "affectionateCat.h"
#include "scaredCat.h"
#include "lazyDog.h"
#include "playfulDog.h"
#include <iostream>

using namespace Shelter;

int main() {

    ScaredCat scaredCat("Simba", 6, "meeeeoooow");
    scaredCat.speak();
    scaredCat.rubBelly();

    ScaredCat scaredCat2("Copy of Simba", 6, "meeeeeeeeeeoooooooooow");
    scaredCat = scaredCat2;
    scaredCat.speak();
    scaredCat.rubBelly();

    AffectionateCat affectionateCat("Kimi", 5, "purrrrrr");
    affectionateCat.speak();
    affectionateCat.rubBelly();

    affectionateCat = AffectionateCat("Older Kimi", 6, "purrrrrrrrr");
    affectionateCat.speak();
    affectionateCat.rubBelly();

    LazyDog lazyDog("Rex", 3, false);
    lazyDog.speak();
    lazyDog.playFetch();

    LazyDog lazyDog2("Copy of Rex", 3, false);
    lazyDog = lazyDog2;
    lazyDog.speak();
    lazyDog.playFetch();

    PlayfulDog playfulDog("Max", 4, true);
    playfulDog.speak();
    playfulDog.playFetch();

    playfulDog = PlayfulDog("Older Max", 5, false);
    playfulDog.speak();
    playfulDog.playFetch();

    return 0;
}