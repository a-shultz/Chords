#include "note.h"

namespace note {

byte getNoteAscending(byte note, byte semitones) {
    byte newNote = note + semitones;
    if (newNote < 12)
        return newNote;
    return newNote - 12;
}

byte getNoteDescending(byte note, byte semitones) {
    byte newNote = (note + 12) - semitones;
    if (newNote < 12)
        return newNote;
    return newNote - 12;
}

int get12BitNote(byte note, byte octave) {
    return (int) round((float) (note * octave) * 34.1333333);
}

void getKeyMajor(byte root, byte* key) {
    key[0] = root;
    key[1] = getNoteAscending(root, 2);
    key[2] = getNoteAscending(root, 4);
    key[3] = getNoteAscending(root, 5);
    key[4] = getNoteAscending(root, 7);
    key[5] = getNoteAscending(root, 9);
    key[6] = getNoteAscending(root, 11);
    key[7] = getNoteAscending(root, 12);
}

void getKeyMinor(byte root, byte* key) {
    key[0] = root;
    key[1] = getNoteAscending(root, 2);
    key[2] = getNoteAscending(root, 3);
    key[3] = getNoteAscending(root, 5);
    key[4] = getNoteAscending(root, 7);
    key[5] = getNoteAscending(root, 8);
    key[6] = getNoteAscending(root, 10);
    key[7] = getNoteAscending(root, 12);
}

void getChord(ChordType type, byte rootIndex, byte* key, byte* chord) {
    switch (type) {
        case ChordType::TRIAD: 
            getChordTriad(rootIndex, key, chord);
            break;
        case ChordType::SEVENTH:
            getChordSeventh(rootIndex, key, chord);
            break;
    }
}

void getChordTriad(byte rootIndex, byte* key, byte* chord) {
    chord[0] = key[rootIndex]; 
    chord[1] = key[getNoteIndex(rootIndex + 2)];
    chord[2] = key[getNoteIndex(rootIndex + 4)];
}

void getChordSeventh(byte rootIndex, byte* key, byte* chord) {
    chord[0] = key[rootIndex]; 
    chord[1] = key[getNoteIndex(rootIndex + 2)];
    chord[2] = key[getNoteIndex(rootIndex + 4)];
    chord[3] = key[getNoteIndex(rootIndex + 6)];
}

void getProgression(ChordType chordType, byte* key, byte** progression) {
    byte current = 0;
    byte size = 0;
    do {
        getChord(chordType, current, key, progression[++size]);
        current = getNextIndex(current);
    } while (current != 0 && size < MAX_CHORD_PROGRESSION_LENGTH);
    if (current != 0 && (current == 2 || current == 5))
        getChord(chordType, 3, key, progression[++size]);
    progression[0][0] = size;
}

byte getNextIndex(byte current) {
    if (current <= 3) {
        if (current == 0) // 0 can move to any position
            return random(1, 7);
        else if (current == 3) { // 3 can move to 0, 1, 4, or 6
            byte next = random(0, 4);
            return next < 2 ? next : next * 2;
        }
        byte next = random(1, 4);
        if (current == 1) // 1 can move to 0, 4, or 6
            return next == 1 ? 0 : next * 2;
        return (next * 2) - 1; // 2 can move to 1, 3, or 5
    }
    else if (current == 5) // 5 can move to 1 or 3
        return random(0, 2) == 0 ? 1 : 3;
    byte next = random(0, 3);
    if (next == 0) // 4 and 6 can both move to 0
        return 0;
    // if next for 4 or 6 is not 0, then 4 can move to 5 or 6 and 6
    // can move to 4 or 5
    return current == 4 ? next + 4 : next + 3;
}

byte getNoteIndex(byte index) {
    if (index < 8)
        return index;
    return index - 8;
}

} // namespace note