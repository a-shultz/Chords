#include <gtest/gtest.h>

#include "chord.h"
#include "key.h"

namespace {

class ChordTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            note::getKey(note::KeyType::MAJOR, note::NoteName::C);
        }

        virtual void TearDown() {
            delete [] note::key;
        }

        note::NoteName* cMajorKey;
};

TEST_F(ChordTest, getChordTriad) {
    note::NoteName triad[3];
    note::getChordTriad(0, triad);
    ASSERT_EQ(triad[0], note::key[0]);
    ASSERT_EQ(triad[1], note::key[2]);
    ASSERT_EQ(triad[2], note::key[4]);
}

TEST_F(ChordTest, getChordSeventh) {
    note::NoteName seventh[4];
    note::getChordSeventh(0, seventh);
    ASSERT_EQ(seventh[0], note::key[0]);
    ASSERT_EQ(seventh[1], note::key[2]);
    ASSERT_EQ(seventh[2], note::key[4]);
    ASSERT_EQ(seventh[3], note::key[6]);
}

TEST_F(ChordTest, getChord) {
    note::NoteName triad[3];
    note::getChord(note::ChordType::TRIAD, 0, triad);
    ASSERT_EQ(triad[0], note::key[0]);
    ASSERT_EQ(triad[1], note::key[2]);
    ASSERT_EQ(triad[2], note::key[4]);
    note::NoteName seventh[4];
    note::getChord(note::ChordType::SEVENTH, 0, seventh);
    ASSERT_EQ(seventh[0], note::key[0]);
    ASSERT_EQ(seventh[1], note::key[2]);
    ASSERT_EQ(seventh[2], note::key[4]);
    ASSERT_EQ(seventh[3], note::key[6]);
}

}