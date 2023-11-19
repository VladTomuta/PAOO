#include "cat.h"

namespace Shelter {
    class AffectionateCat: public Cat {

    public:
        AffectionateCat(std::string name, int age, std::string say);
        ~AffectionateCat();
        AffectionateCat(const AffectionateCat &affectionateCat);
        AffectionateCat(AffectionateCat &&affectionateCat);

        AffectionateCat& operator=(const AffectionateCat &affectionateCat);
        AffectionateCat& operator=(AffectionateCat &&affectionateCat);

        void rubBelly() const;
    };
}