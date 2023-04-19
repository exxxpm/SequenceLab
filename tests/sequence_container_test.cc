#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace sequence;


TEST(SequanceContainerTests, CapacityCheck) {
    SequanceContainer sequence(3);
    SequanceItem elem = SequanceItem(ARITHMETIC, 1, 2, 0);
    sequence[0] = SequanceItem(GEOMETRIC, 3, 0, 6);
    sequence[1] = SequanceItem(ARITHMETIC, 2, 8, 0);
    sequence[2] = SequanceItem(GEOMETRIC, 1, 0, 2);
    ASSERT_ANY_THROW(sequence.insert(4, elem));
}

TEST(MaxSumNthElemIndex, NoResult) {
    SequanceContainer sequence;
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, -1);
}

TEST(MaxSumNthElemIndex, ForArithmetics1) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(ARITHMETIC, 1, 2, 0);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 1, 4, 0);
    sequence.insert(1, elem);
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ForArithmetics2) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(ARITHMETIC, 1, 2, 0);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 1, 8, 0);
    sequence.insert(1, elem);
    elem = SequanceItem(ARITHMETIC, 1, 7, 0);
    sequence.insert(2, elem);
    elem = SequanceItem(ARITHMETIC, 1, 4, 0);
    sequence.insert(3, elem);
    const auto index = max_summ_nth_elem(sequence, 8);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ForGeometrics1) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 2, 0, 4);
    sequence.insert(0, elem);
    elem = SequanceItem(GEOMETRIC, 2, 0, 2);
    sequence.insert(1, elem);
    elem = SequanceItem(GEOMETRIC, 2, 0, 6);
    sequence.insert(2, elem);
    elem = SequanceItem(GEOMETRIC, 2, 0, 9);
    sequence.insert(3, elem);
    const auto index = max_summ_nth_elem(sequence, 5);
    ASSERT_EQ(index, 3);
}

TEST(MaxSumNthElemIndex, ForGeometrics2) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 5, 0, 4);
    sequence.insert(0, elem);
    elem = SequanceItem(GEOMETRIC, 7, 0, 4);
    sequence.insert(1, elem);
    elem = SequanceItem(GEOMETRIC, 2, 0, 9);
    sequence.insert(2, elem);
    elem = SequanceItem(GEOMETRIC, 4, 0, 3);
    sequence.insert(3, elem);
    const auto index = max_summ_nth_elem(sequence, 2);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics1) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 1, 0, 2);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 2, 8, 0);
    sequence.insert(1, elem);
    elem = SequanceItem(GEOMETRIC, 3, 0, 6);
    sequence.insert(2, elem);
    elem = SequanceItem(ARITHMETIC, 6, 18, 0);
    sequence.insert(3, elem);
    const auto index = max_summ_nth_elem(sequence, 9);
    ASSERT_EQ(index, 2);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics2) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 2, 0, 4);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 1, 10, 0);
    sequence.insert(1, elem);
    elem = SequanceItem(ARITHMETIC, 1, 5, 0);
    sequence.insert(2, elem);
    elem = SequanceItem(ARITHMETIC, 8, 20, 0);
    sequence.insert(3, elem);
    const auto index = max_summ_nth_elem(sequence, 1);
    ASSERT_EQ(index, 3);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics3) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 7, 0, 14);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 2, 5, 0);
    sequence.insert(1, elem);
    elem = SequanceItem(GEOMETRIC, 6, 0, 12);
    sequence.insert(2, elem);
    elem = SequanceItem(GEOMETRIC, 1, 0, 8);
    sequence.insert(3, elem);
    const auto index = max_summ_nth_elem(sequence, 4);
    ASSERT_EQ(index, 0);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics4) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 1, 0, 4);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 2, 4, 0);
    sequence.insert(1, elem);
    elem = SequanceItem(GEOMETRIC, 2, 0, 4);
    sequence.insert(2, elem);
    elem = SequanceItem(GEOMETRIC, 1, 0, 8);
    sequence.insert(3, elem);
    elem = SequanceItem(GEOMETRIC, 3, 0, 9);
    sequence.insert(4, elem);
    elem = SequanceItem(ARITHMETIC, 3, 13, 0);
    sequence.insert(5, elem);
    elem = SequanceItem(GEOMETRIC, 3, 0, 16);
    sequence.insert(6, elem);
    elem = SequanceItem(GEOMETRIC, 8, 0, 16);
    sequence.insert(7, elem);
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, 7);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics5) {
    SequanceContainer sequence;
    SequanceItem elem = SequanceItem(GEOMETRIC, 2, 0, 6);
    sequence.insert(0, elem);
    elem = SequanceItem(ARITHMETIC, 6, 12, 0);
    sequence.insert(1, elem);
    elem = SequanceItem(GEOMETRIC, 3, 0, 7);
    sequence.insert(2, elem);
    elem = SequanceItem(GEOMETRIC, 4, 0, 12);
    sequence.insert(3, elem);
    elem = SequanceItem(GEOMETRIC, 6, 0, 9);
    sequence.insert(4, elem);
    elem = SequanceItem(ARITHMETIC, 7, 14, 0);
    sequence.insert(5, elem);
    elem = SequanceItem(GEOMETRIC, 5, 0, 10);
    sequence.insert(6, elem);
    elem = SequanceItem(GEOMETRIC, 1, 0, 10);
    sequence.insert(7, elem);
    elem = SequanceItem(GEOMETRIC, 8, 0, 16);
    sequence.insert(8, elem);
    elem = SequanceItem(ARITHMETIC, 6, 9, 0);
    sequence.insert(9, elem);
    const auto index = max_summ_nth_elem(sequence, 4);
    ASSERT_EQ(index, 8);
}