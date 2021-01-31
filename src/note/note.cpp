#include "note.h"

namespace note {

NoteName& operator++(NoteName& note) {
    byte value = static_cast<byte>(note) + 1;
    if (value >= 12)
        value -= 12;
    note = static_cast<NoteName>(value);
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