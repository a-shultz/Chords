#include "chord.h"

namespace note {

void getChord(ChordType type, byte rootIndex, NoteName* key, NoteName* chord) {
    switch (type) {
        case ChordType::TRIAD: 
            getChordTriad(rootIndex, key, chord);
            break;
        case ChordType::SEVENTH:
            getChordSeventh(rootIndex, key, chord);
            break;
    }
}

void getChordTriad(byte rootIndex, NoteName* key, NoteName* chord) {
    chord[0] = key[rootIndex]; 
    chord[1] = key[getNoteIndex(rootIndex + 2)];
    chord[2] = key[getNoteIndex(rootIndex + 4)];
}

void getChordSeventh(byte rootIndex, NoteName* key, NoteName* chord) {
    chord[0] = key[rootIndex]; 
    chord[1] = key[getNoteIndex(rootIndex + 2)];
    chord[2] = key[getNoteIndex(rootIndex + 4)];
    chord[3] = key[getNoteIndex(rootIndex + 6)];
}

byte getNoteIndex(byte index) {
    if (index < 8)
        return index;
    return index - 8;
}

} // namespace note