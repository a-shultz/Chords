#ifndef KEY_H
#define KEY_H

#include <Arduino.h>

#include <stdlib.h> 

#include "note.h"

#define MAJOR_KEY_LENGTH 8
#define MINOR_KEY_LENGTH 8

namespace note {
/*! @brief Current key */
extern NoteName* key;
/*! @brief Current key length */
extern byte keyLength;
/*! @brief Type of key. */
enum class KeyType : byte { MAJOR, MINOR };
/**
 * Get the key for a root note.
 * 
 * @param type key type.
 * @param root root note.
 * @param key pointer to target destination.
 */
NoteName* getKey(KeyType type, NoteName root);
/**
 * Assign the major key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
NoteName* getKeyMajor(NoteName root);
/**
 * Assign the minor key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
NoteName* getKeyMinor(NoteName root);
} // namespace note

#endif /* KEY_H */