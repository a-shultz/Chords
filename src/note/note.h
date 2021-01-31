#ifndef NOTE_H
#define NOTE_H

#include <Arduino.h>

namespace note {
/**
 * Get the note at the number of semitones above the provided 
 * note.
 * 
 * Equivalent to (note + semitones) mod 12.
 * 
 * @param note note value 0 - 11.
 * @param semitones number of semitones to increase the note by.
 * 0 <= semitone <= 12.
 * @return note at the number of semitones above the provided 
 * note.
 */
byte getNoteAscending(byte note, byte semitones);
/**
 * Get the note at the number of semitones below the provided 
 * note.
 * 
 * Equivalent to (note - semitones) mod 12.
 * 
 * @param note note value 0 - 11.
 * @param semitones number of semitones to decrease the note by.
 * 0 <= semitone <= 12.
 * @return note at the number of semitones below the provided
 * note.
 */
byte getNoteDescending(byte note, byte semitones);
/**
 * Get the 12 bit representation of the note value with octave.
 * 
 * @param note note value 0 - 11.
 * @param octave value between 1 and 10.
 * @return 12 bir representation of the note.
 */
int get12BitNote(byte note, byte octave);
} // namespace note

#endif /* NOTE_H */