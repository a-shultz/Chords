#include "key.h"

#include "note.h"

namespace note {

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

} // namespace note