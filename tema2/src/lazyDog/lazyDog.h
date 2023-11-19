#include "dog.h"

namespace Shelter {
    class LazyDog: public Dog {

    public:
        LazyDog(std::string name, int age, bool isTailWagging);
        ~LazyDog();
        LazyDog(const LazyDog &lazyDog);
        LazyDog(LazyDog &&lazyDog);

        LazyDog& operator=(const LazyDog &lazyDog);
        LazyDog& operator=(LazyDog &&lazyDog);

        void playFetch() const;
    };
}