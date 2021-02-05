#ifndef RNG_08_H
#define RNG_08_H

#include <Arduino.h>

class RNG08 {
    private:
        volatile byte lfsr;

    public:
        RNG08(byte seed);
        void setSeed(byte seed);
        byte get();

    private:
        void next();
};

#endif /* RNG_08_H */