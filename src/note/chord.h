#ifndef CHORD_H
#define CHORD_H

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
} // namespace note

#endif /* CHORD_H */