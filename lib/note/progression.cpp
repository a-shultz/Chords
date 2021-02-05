#include "progression.h"

namespace note {

void getProgression(ChordType chordType, NoteName* key, NoteName** progression) {
    byte current = 0;
    byte size = 0;
    do {
        getChord(chordType, current, progression[size++]);
        current = getNextIndex(current);
    } while (current != 0 && size < MAX_PROGRESSION_LENGTH);
    if (current != 0 && (current == 2 || current == 5))
        getChord(chordType, 3, progression[size++]);
}

byte getNextIndex(byte current) {
    byte randomNumber = rng.get08();
    switch (current) {
        case 0: return step0[MOD6(randomNumber)];
        case 1: return step1[MOD3(randomNumber)];
        case 2: return step2[MOD3(randomNumber)];
        case 3: return step3[MOD4(randomNumber)];
        case 4: return step4[MOD3(randomNumber)];
        case 5: return step5[MOD2(randomNumber)];
        case 6: return step6[MOD3(randomNumber)];
    }
}

} // namespace note