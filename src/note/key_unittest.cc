#include <gtest/gtest.h>

#include "key.h"

namespace {

class KeyTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            cMajorKey = new note::NoteName[8] {
                note::NoteName::C,
                note::NoteName::D,
                note::NoteName::E,
                note::NoteName::F,
                note::NoteName::G,
                note::NoteName::A,
                note::NoteName::B,
                note::NoteName::C
            };

            cSharpMajorKey = new note::NoteName[8] {
                note::NoteName::C_S,
                note::NoteName::D_S,
                note::NoteName::F,
                note::NoteName::F_S,
                note::NoteName::G_S,
                note::NoteName::A_S,
                note::NoteName::C,
                note::NoteName::C_S
            };

            cMinorKey = new note::NoteName[8] {
                note::NoteName::C,
                note::NoteName::D,
                note::NoteName::D_S,
                note::NoteName::F,
                note::NoteName::G,
                note::NoteName::G_S,
                note::NoteName::A_S,
                note::NoteName::C
            };

            cSharpMinorKey = new note::NoteName[8] {
                note::NoteName::C_S,
                note::NoteName::D_S,
                note::NoteName::E,
                note::NoteName::F_S,
                note::NoteName::G_S,
                note::NoteName::A,
                note::NoteName::B,
                note::NoteName::C_S
            };
        }

        virtual void TearDown() {
            delete [] cMajorKey;
            delete [] cSharpMajorKey;
            delete [] cMinorKey;
            delete [] cSharpMinorKey;
        }

        note::NoteName* cMajorKey;
        note::NoteName* cSharpMajorKey;
        note::NoteName* cMinorKey;
        note::NoteName* cSharpMinorKey;

        void assertKeyEqual(note::NoteName* valid, byte validLength) {
            ASSERT_EQ(note::keyLength, validLength);
            for (byte i = 0; i < validLength; ++i)
                ASSERT_EQ(note::key[i], valid[i]);
        }
};

TEST_F(KeyTest, getKeyMajor) {
    note::NoteName* undefKeyPtr = note::key;
    note::NoteName* cKeyPtr = note::getKeyMajor(note::NoteName::C);
    ASSERT_EQ(undefKeyPtr, cKeyPtr);
    assertKeyEqual(cMajorKey, 8);
    note::NoteName* cSharpKeyPtr = note::getKeyMajor(note::NoteName::C_S);
    ASSERT_EQ(cKeyPtr, cSharpKeyPtr);
    assertKeyEqual(cSharpMajorKey, 8);
}

TEST_F(KeyTest, getKeyMinor) {
    note::NoteName* undefKeyPtr = note::key;
    note::NoteName* cKeyPtr = note::getKeyMinor(note::NoteName::C);
    ASSERT_EQ(undefKeyPtr, cKeyPtr);
    assertKeyEqual(cMinorKey, 8);
    note::NoteName* cSharpKeyPtr = note::getKeyMinor(note::NoteName::C_S);
    ASSERT_EQ(note::keyLength, 8);
    assertKeyEqual(cSharpMinorKey, 8);
}

TEST_F(KeyTest, getKey) {
    note::NoteName* undefKey = note::key;
    note::NoteName* cMajorKey = note::getKey(note::KeyType::MAJOR, note::NoteName::C);
    ASSERT_EQ(undefKey, cMajorKey);
    assertKeyEqual(cMajorKey, 8);
    note::NoteName* cMinorKey = note::getKey(note::KeyType::MINOR, note::NoteName::C);
    ASSERT_EQ(undefKey, cMinorKey);
    assertKeyEqual(cMinorKey, 8);
}

}