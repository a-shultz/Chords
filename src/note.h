#ifndef NOTE_H
#define NOTE_H

#define MAX_CHORD_PROGRESSION_LENGTH 5

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
byte ascend(byte note, byte semitones);
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
byte descend(byte note, byte semitones);
/**
 * Get the 12 bit representation of the note value with octave.
 * 
 * @param note note value 0 - 11.
 * @param octave value between 1 and 10.
 * @return 12 bir representation of the note.
 */
int get12BitNote(byte note, byte octave);

namespace key {
/**
 * Assign the major key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
void getMajor(byte root, byte* key);
/**
 * Assign the minor key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
void getMinor(byte root, byte* key);
} // namespace key

namespace chord {
/**
 * Assign the chord at the root index in a key to the array 
 * pointer.
 * 
 * @param rootIndex index of the root note in the chord.
 * @param key pointer to array containing the key notes.
 * @param chord pointer to array to assign chord notes to.
 */
void get(byte rootIndex, byte* key, byte* chord);
/**
 * Get random chord progression between 2 and 5 chords long.
 * 
 * @param key chord key
 * @param progression 6 x 4 array to hold progression chord notes.
 * progression[0][0] contains the resulting size of progression.
 */
void getProgression(byte* key, byte** progression);
} // namespace chord
} // namespace note

#endif /* NOTE_H */