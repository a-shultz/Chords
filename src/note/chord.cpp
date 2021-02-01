#include "chord.h"

#include "key.h"

namespace note {

NoteName getKeyNote(byte index);

void getChord(ChordType type, byte rootIndex, NoteName* chord) {
    switch (type) {
        case ChordType::TRIAD: 
            getChordTriad(rootIndex, chord);
            break;
        case ChordType::SEVENTH:
            getChordSeventh(rootIndex, chord);
            break;
    }
}

void getChordTriad(byte rootIndex, NoteName* chord) {
    chord[0] = getKeyNote(rootIndex); 
    chord[1] = getKeyNote(rootIndex + 2);
    chord[2] = getKeyNote(rootIndex + 4);
}

void getChordSeventh(byte rootIndex, NoteName* chord) {
    chord[0] = getKeyNote(rootIndex); 
    chord[1] = getKeyNote(rootIndex + 2);
    chord[2] = getKeyNote(rootIndex + 4);
    chord[3] = getKeyNote(rootIndex + 6);
}

NoteName getKeyNote(byte index) {
    if (index < 8)
        return key[index];
    return key[index - 8];
}

} // namespace note