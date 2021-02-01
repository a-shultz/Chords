#ifndef PROGRESSION_H
#define PROGRESSION_H

#ifdef ARDUINO_VERSION
#include <Arduino.h>
#else
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t byte;

#define random(min, max) static_cast<byte>(rand()) % max + min

#endif

#include "chord.h"
#include "note.h"

namespace note {
/*! Maximum chord progression length */
const byte MAX_PROGRESSION_LENGTH = 5;
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