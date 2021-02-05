#include "rng-16.h"

#ifdef __INTELLISENSE__
    #pragma diag_suppress 1118
#endif

RNG16::RNG16(word seed) {
    lfsr = seed;
}

void RNG16::setSeed(word seed) {
    lfsr = seed;
}

word RNG16::get() {
    next();
    return lfsr;
}

byte RNG16::get08() {
    next();
    byte result = 0;
    asm volatile (
        "mov %0, %B1 \n"
        : "=r" (result)
        : "r" (lfsr)
        :
    );
    return result;
}

void RNG16::next() {
    asm volatile (
            "mov r16, %A0 \n"
            "ldi r17, 0x2D \n"
            "lsl %B0 \n"
            "rol %A0 \n"
            "sbrc r16, 7 \n"
            "eor %B0, r17 \n"
        "msb_not_set: \n"
        : "=r" (lfsr)
        : "0" (lfsr)
        : "r16", "r17"
    ); \
}