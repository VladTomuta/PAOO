#include "dog.h"

namespace Shelter {
    class PlayfulDog: public Dog {

    public:
        PlayfulDog(std::string name, int age, bool isTailWagging);
        ~PlayfulDog();
        PlayfulDog(const PlayfulDog &playfulDog);
        PlayfulDog(PlayfulDog &&playfulDog);

        PlayfulDog& operator=(const PlayfulDog &playfulDog);
        PlayfulDog& operator=(PlayfulDog &&playfulDog);

        void playFetch() const;
    };
}