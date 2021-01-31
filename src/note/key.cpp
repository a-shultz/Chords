#include "key.h"

#include "note.h"

namespace note {

void getKey(KeyType type, NoteName root, NoteName* key) {
    switch (type) {
        case KeyType::MAJOR: 
            getKeyMajor(root, key);
            break;
        case KeyType::MINOR:
            getKeyMajor(root, key);
            break;
    }
}

void getKeyMajor(NoteName root, NoteName* key) {
    key[0] = root;
    key[1] = root + 2;
    key[2] = root + 4;
    key[3] = root + 5;
    key[4] = root + 7;
    key[5] = root + 9;
    key[6] = root + 11;
    key[7] = root + 12;
}

void getKeyMinor(NoteName root, NoteName* key) {
    key[0] = root;
    key[1] = root + 2;
    key[2] = root + 3;
    key[3] = root + 5;
    key[4] = root + 7;
    key[5] = root + 8;
    key[6] = root + 10;
    key[7] = root + 12;
}

} // namespace note