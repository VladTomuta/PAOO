#include "cat.h"

namespace Shelter {
    class ScaredCat: public Cat {

    public:
        ScaredCat(std::string name, int age, std::string say);
        ~ScaredCat();
        ScaredCat(const ScaredCat &scaredCat);
        ScaredCat(ScaredCat &&scaredCat);

        ScaredCat& operator=(const ScaredCat &scaredCat);
        ScaredCat& operator=(ScaredCat &&scaredCat);

        void rubBelly() const;
    };
}