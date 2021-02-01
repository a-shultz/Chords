#include <gtest/gtest.h>

#include "note.h"

namespace {

    TEST(NoteTest, Addition) {
        note::NoteName n = note::NoteName::C;
        ASSERT_EQ(static_cast<byte>(n), 0);
        ASSERT_EQ(n + 2, note::NoteName::D);
        ASSERT_EQ(n + 0, note::NoteName::C);
        ASSERT_EQ(n + 12, note::NoteName::C);
    }

    TEST(NoteTest, Subtraction) {
        ASSERT_EQ(note::NoteName::C - 1, note::NoteName::B);
        ASSERT_EQ(note::NoteName::C - 12, note::NoteName::C);
        ASSERT_EQ(note::NoteName::A - 4, note::NoteName::F);
    }

    TEST(NoteTest, PreIncrement) {
        note::NoteName n = note::NoteName::C;
        note::NoteName incremented = ++n;
        ASSERT_EQ(n, note::NoteName::C_S);
        ASSERT_EQ(incremented, note::NoteName::C_S);
    }

    TEST(NoteTest, PostIncrement) {
        note::NoteName n = note::NoteName::C;
        note::NoteName incremented = n++;
        ASSERT_EQ(n, note::NoteName::C_S);
        ASSERT_EQ(incremented, note::NoteName::C);
    }

    TEST(NoteTest, PreDecrement) {
        note::NoteName n = note::NoteName::C;
        note::NoteName decremented = --n;
        ASSERT_EQ(n, note::NoteName::B);
        ASSERT_EQ(decremented, note::NoteName::B);
    }

    TEST(NoteTest, PostDecrement) {
        note::NoteName n = note::NoteName::C;
        note::NoteName decremented = n--;
        ASSERT_EQ(n, note::NoteName::B);
        ASSERT_EQ(decremented, note::NoteName::C);
    }

    TEST(NoteTest, AdditionAssigment) {
        note::NoteName n = note::NoteName::C;
        n += 2;
        ASSERT_EQ(n, note::NoteName::D);
    }

    TEST(NoteTest, SubtractionAssignment) {
        note::NoteName n = note::NoteName::C;
        n -= 2;
        ASSERT_EQ(n, note::NoteName::A_S);
    }

    TEST(NoteTest, ConvertTo12Bit) {
        ASSERT_EQ(note::get12BitNote(note::NoteName::C, 2), 819);
    }
}