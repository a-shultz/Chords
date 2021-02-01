#include "key.h"

namespace note {

NoteName* key = static_cast<NoteName*>(malloc(0));
byte keyLength = 0;

void reallocateKey(byte length) {
    key = static_cast<NoteName*>(realloc(key, sizeof(NoteName) * length));
    keyLength = length;
}

NoteName* getKey(KeyType type, NoteName root) {
    switch (type) {
        case KeyType::MAJOR: return getKeyMajor(root);
        case KeyType::MINOR: return getKeyMajor(root);
    }
}

NoteName* getKeyMajor(NoteName root) {
    if (keyLength != MAJOR_KEY_LENGTH)
        reallocateKey(MAJOR_KEY_LENGTH);
    key[0] = root;
    key[1] = root + 2;
    key[2] = root + 4;
    key[3] = root + 5;
    key[4] = root + 7;
    key[5] = root + 9;
    key[6] = root + 11;
    key[7] = root + 12;
    return key;
}

NoteName* getKeyMinor(NoteName root) {
    if (keyLength != MINOR_KEY_LENGTH)
        reallocateKey(MINOR_KEY_LENGTH);
    key[0] = root;
    key[1] = root + 2;
    key[2] = root + 3;
    key[3] = root + 5;
    key[4] = root + 7;
    key[5] = root + 8;
    key[6] = root + 10;
    key[7] = root + 12;
    return key;
}

} // namespace note