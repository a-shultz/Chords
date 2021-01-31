#ifndef KEY_H
#define KEY_H

#include <Arduino.h>

namespace note {
/*! @brief Type of key. */
enum class KeyType : byte { MAJOR, MINOR };
/**
 * Get the key for a root note.
 * 
 * @param type key type.
 * @param root root note.
 * @param key pointer to target destination.
 */
void getKey(KeyType type, NoteName root, NoteName* key);
/**
 * Assign the major key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
void getKeyMajor(NoteName root, NoteName* key);
/**
 * Assign the minor key for the provided root note to the provided
 * array pointer.
 * 
 * @param root root note for key.
 * @param key array pointer to copy key notes to.
 */
void getKeyMinor(NoteName root, NoteName* key);
} // namespace note

#endif /* KEY_H */