#ifndef NOTE_H
#define NOTE_H

#define MAX_CHORD_PROGRESSION_LENGTH 5

#include <Arduino.h>

namespace note {
/*! @brief Type of chord.
 *
 * Each type refers to a different format for indexing the key to
 * create a chord.
 * 
 * symbol  | index format
 * ------- | ------
 * TRIAD   | [0, 2, 4]
 * SEVENTH | [0, 2, 4, 6]
 */
enum class ChordType { TRIAD, SEVENTH };
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
/**
 * Assign the major key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
void getKeyMajor(byte root, byte* key);
/**
 * Assign the minor key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
void getKeyMinor(byte root, byte* key);
/**
 * Get the chord for the root note within a key.
 * 
 * @param type type of chord.
 * @param rootIndex index of the root note for the chord.
 * @param key pointer to the chord's key.
 * @param chord pointer to the target destination.
 */
void getChord(ChordType type, byte rootIndex, byte* key, byte* chord);
/**
 * Get the triad chord for the root note within the provided key.
 * 
 * @param rootIndex index of the root note for the chord.
 * @param key pointer to the chord's key.
 * @param chord pointer to the target destination of the key.
 */
void getChordTriad(byte rootIndex, byte* key, byte* chord);
/**
 * Get the seventh chord for the root note within the provided key.
 * 
 * @param rootIndex index of the root note for the chord.
 * @param key pointer to the chord's key.
 * @param chord pointer to the target destination of the key.
 */
void getChordSeventh(byte rootIndex, byte* key, byte* chord);
/**
 * Get a random chord progression between 2 and 5 chords long.
 * 
 * @param chordType the type of chord to generate.
 * @param key chord key
 * @param progression 6 x 4 array to hold progression chord notes.
 * progression[0][0] contains the resulting size of progression.
 */
void getProgression(ChordType chordType, byte* key, byte** progression);
} // namespace chord

#endif /* NOTE_H */