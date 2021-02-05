#ifndef PROGRESSION_H
#define PROGRESSION_H

#include <Arduino.h>

#include "chord.h"
#include "note.h"
#include "../random/rng-16.h"

#define MOD6(x) ({ \
    asm volatile ( \
            "andi %0, 0x07 \n" \
            "cpi %0, 0x06 \n" \
            "brlo mod_six_end \n" \
            "subi %0, 0x06 \n" \
        "mod_six_end: \n" \
        : "=r" (x) \
        : "0" (x) \
        : \
    ); \
    x; \
})

#define MOD4(x) ({ \
    asm volatile ( \
        "andi %0, 0x03 \n" \
        : "=r" (x) \
        : "0" (x) \
        : \
    ); \
    x; \
})

#define MOD3(x) ({ \
    asm volatile ( \
            "andi %0, 0x03 \n" \
            "cpi %0, 0x2 \n" \
            "brlo mod_two_end \n" \
            "subi %0, 0x02 \n" \
        "mod_two_end: \n" \
        : "=r" (x) \
        : "0" (x) \
        : \
    ); \
    x; \
})

#define MOD2(x) ({ \
    asm volatile ( \
        "andi %0, 0x01 \n" \
        : "=r" (x) \
        : "0" (x) \
        : \
    ); \
    x; \
})

namespace note {
/*! Maximum chord progression length */
const byte MAX_PROGRESSION_LENGTH = 5;

RNG16 rng(analogRead(A0));

const byte step0[] PROGMEM = { 1, 2, 3, 4, 5, 6 };
const byte step1[] PROGMEM = { 0, 4, 6 };
const byte step2[] PROGMEM = { 1, 3, 5 };
const byte step3[] PROGMEM = { 0, 1, 4, 6 };
const byte step4[] PROGMEM = { 0, 5, 6 };
const byte step5[] PROGMEM = { 1, 3 };
const byte step6[] PROGMEM = { 0, 4, 5 };

/**
 * Get a random chord progression between 2 and 5 chords long.
 * 
 * @param chordType the type of chord to generate.
 * @param key chord key
 * @param progression 5 x (chord type) array to hold progression chord notes.
 * progression[0][0] contains the resulting size of progression.
 */
void getProgression(ChordType chordType, NoteName* key, NoteName** progression);
} // namespace note

#endif /* PROGRESSION_H */