#ifndef NOTE_H
#define NOTE_H

#include <Arduino.h>

namespace note {
/*! @brief Note names */
enum class NoteName : byte { C, C_S, D, D_S, E, F, F_S, G, G_S, A, A_S, B };
/**
 * Get the NoteName x semitones above the provided note.
 * 
 * @note x should not be greater than 12.
 */
NoteName operator+(NoteName note, byte x);
/**
 * Get the NoteName x semitones below the provided note.
 * 
 * @note x should not be greater than 12.
 */
NoteName operator-(NoteName note, byte x);
/**
 * Set the current NoteName one semitone higher.
 */
NoteName& operator++(NoteName& note);
/**
 * Return the current NoteName and set it one semitone higher.
 */
NoteName operator++(NoteName& note, int);
/**
 * Set the current NoteName one semitone lower.
 */
NoteName& operator--(NoteName& note);
/**
 * Return the current NoteName and set it one semitone higher.
 */
NoteName operator++(NoteName& note, int);
/**
 * Set the current NoteName x semitones higher.
 */
NoteName& operator+=(NoteName& note, const byte& x);
/**
 * Set the current NoteName x semitones lower.
 */
NoteName& operator-=(NoteName& note, const byte& x);

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