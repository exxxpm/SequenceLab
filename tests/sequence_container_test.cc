#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace sequence;


TEST(SequanceContainerTests, DatasizeCheck) {
    SequanceContainer sequence;
    const auto temp = SequanceItem::SequanceItem(ARITHMETIC, 0, 0, 0);
    for (int item = 0; item < SequanceContainer::DATASIZE; ++item) {
        sequence.insert(item, temp);
    }
    ASSERT_ANY_THROW(sequence.insert(10, temp));
}

TEST(MaxSumNthElemIndex, NoResult) {
    SequanceContainer sequence;
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, -1);
}

TEST(MaxSumNthElemIndex, ForArithmetics1) {
    SequanceContainer sequence;
    sequence.insert(0, SequanceItem::SequanceItem(ARITHMETIC, 1, 2, 0));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 1, 4, 0));
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ForArithmetics2) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(ARITHMETIC, 1, 2, 0));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 1, 8, 0));
    sequence.insert(2, SequanceItem::SequanceItem(ARITHMETIC, 1, 7, 0));
    sequence.insert(3, SequanceItem::SequanceItem(ARITHMETIC, 1, 4, 0));

    const auto index = max_summ_nth_elem(sequence, 8);

    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ForGeometrics1) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 4));
    sequence.insert(1, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 2));
    sequence.insert(2, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 6));
    sequence.insert(3, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 9));

    const auto index = max_summ_nth_elem(sequence, 5);

    ASSERT_EQ(index, 3);
}

TEST(MaxSumNthElemIndex, ForGeometrics2) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 5, 0, 4));
    sequence.insert(1, SequanceItem::SequanceItem(GEOMETRIC, 7, 0, 4));
    sequence.insert(2, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 9));
    sequence.insert(3, SequanceItem::SequanceItem(GEOMETRIC, 4, 0, 3));

    const auto index = max_summ_nth_elem(sequence, 2);

    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics1) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 1, 0, 2));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 2, 8, 0));
    sequence.insert(2, SequanceItem::SequanceItem(GEOMETRIC, 3, 0, 6));
    sequence.insert(3, SequanceItem::SequanceItem(ARITHMETIC, 6, 18, 0));

    const auto index = max_summ_nth_elem(sequence, 9);

    ASSERT_EQ(index, 2);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics2) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 4));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 1, 10, 0));
    sequence.insert(3, SequanceItem::SequanceItem(ARITHMETIC, 1, 5, 0));
    sequence.insert(3, SequanceItem::SequanceItem(ARITHMETIC, 8, 20, 0));

    const auto index = max_summ_nth_elem(sequence, 1);

    ASSERT_EQ(index, 3);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics3) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 7, 0, 14));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 2, 5, 0));
    sequence.insert(2, SequanceItem::SequanceItem(GEOMETRIC, 6, 0, 12));
    sequence.insert(3, SequanceItem::SequanceItem(GEOMETRIC, 1, 0, 8));

    const auto index = max_summ_nth_elem(sequence, 4);

    ASSERT_EQ(index, 0);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics4) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 1, 0, 4));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 2, 4, 0));
    sequence.insert(2, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 4));
    sequence.insert(3, SequanceItem::SequanceItem(GEOMETRIC, 8, 0, 16));
    sequence.insert(4, SequanceItem::SequanceItem(GEOMETRIC, 3, 0, 9));
    sequence.insert(5, SequanceItem::SequanceItem(ARITHMETIC, 3, 13, 0));
    sequence.insert(6, SequanceItem::SequanceItem(GEOMETRIC, 3, 0, 16));
    sequence.insert(7, SequanceItem::SequanceItem(GEOMETRIC, 8, 0, 16));

    const auto index = max_summ_nth_elem(sequence, 10);

    ASSERT_EQ(index, 7);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics5) {
    SequanceContainer sequence;

    sequence.insert(0, SequanceItem::SequanceItem(GEOMETRIC, 2, 0, 6));
    sequence.insert(1, SequanceItem::SequanceItem(ARITHMETIC, 6, 12, 0));
    sequence.insert(2, SequanceItem::SequanceItem(GEOMETRIC, 3, 0, 7));
    sequence.insert(3, SequanceItem::SequanceItem(GEOMETRIC, 4, 0, 12));
    sequence.insert(4, SequanceItem::SequanceItem(GEOMETRIC, 6, 0, 9));
    sequence.insert(5, SequanceItem::SequanceItem(ARITHMETIC, 7, 14, 0));
    sequence.insert(6, SequanceItem::SequanceItem(GEOMETRIC, 5, 0, 10));
    sequence.insert(7, SequanceItem::SequanceItem(GEOMETRIC, 1, 0, 10));
    sequence.insert(8, SequanceItem::SequanceItem(GEOMETRIC, 8, 0, 16));
    sequence.insert(9, SequanceItem::SequanceItem(ARITHMETIC, 6, 9, 0));

    const auto index = max_summ_nth_elem(sequence, 4);

    ASSERT_EQ(index, 8);
}