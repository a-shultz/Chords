#include "note.h"

namespace note {

NoteName operator+(NoteName note, byte x) {
    byte value = static_cast<byte>(note) + x;
    if (value >= 12)
        value -= 12;
    return static_cast<NoteName>(value);
}

NoteName operator-(NoteName note, byte x) {
    byte value = (static_cast<byte>(note) + 12) - x;
    if (value >= 12)
        value -= 12;
    return static_cast<NoteName>(value);
}

NoteName& operator++(NoteName& note) {
    note = note + 1;
    return note;
}

NoteName operator++(NoteName& note, int) {
    NoteName current = note;
    note = note + 1;
    return current;
}

NoteName& operator--(NoteName& note) {
    note = note - 1;
    return note;
}

NoteName operator--(NoteName& note, int) {
    NoteName current = note;
    note = note - 1;
    return current;
}

NoteName& operator+=(NoteName& note, const byte& x) {
    note = note + x;
    return note;
}

NoteName& operator-=(NoteName& note, const byte& x) {
    note = note - x;
    return note;
}

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

} // namespace note