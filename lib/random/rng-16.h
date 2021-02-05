#ifndef RNG_16_H
#define RNG_16_H

#include <Arduino.h>

class RNG16 {
    private:
        volatile word lfsr;

    public:
        RNG16(word seed);
        void setSeed(word seed);
        word get();
        byte get08();

    private:
        void next();
};

#endif /* RNG_16_H */