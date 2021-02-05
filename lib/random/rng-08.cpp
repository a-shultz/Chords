#include "rng-08.h"

#ifdef __INTELLISENSE__
    #pragma diag_suppress 1118
#endif

RNG08::RNG08(byte seed) {
    setSeed(seed);
}

void RNG08::setSeed(byte seed) {
    lfsr = seed;
}

byte RNG08::get() {
    next();
    return lfsr;
}

void RNG08::next() {
    asm volatile (
        "mov r16, %0 \n"
        "ldi r17, 0x7F \n"
        "lsl %0 \n"
        "sbrs r16, 7 \n"
        "eor %0, r17 \n"
        : "=r" (lfsr)
        : "0" (lfsr)
        : "r16", "r17"
    );
}