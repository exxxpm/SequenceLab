#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace sequence;
using namespace std;

TEST(MaxSumNthElemIndex, NoResult) {
    SequanceContainer sequence;
    const auto index = max_summ_nth_elem(sequence, 0);
    ASSERT_EQ(index, -1);
}

TEST(MaxSumNthElemIndex, ForArithmetics1) {
    SequanceContainer sequence;
    sequence.insert(make_shared<ArithmeticSequance>(1, 2));
    sequence.insert(make_shared<ArithmeticSequance>(1, 4));
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ForArithmetics2) {
    SequanceContainer sequence;
    sequence.insert(make_shared<ArithmeticSequance>(1, 2));
    sequence.insert(make_shared<ArithmeticSequance>(1, 8));
    sequence.insert(make_shared<ArithmeticSequance>(1, 7));
    sequence.insert(make_shared<ArithmeticSequance>(1, 4));
    const auto index = max_summ_nth_elem(sequence, 8);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ForGeometrics1) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(2, 4));
    sequence.insert(make_shared<GeometricSequance>(2, 2));
    sequence.insert(make_shared<GeometricSequance>(2, 6));
    sequence.insert(make_shared<GeometricSequance>(2, 9));
    const auto index = max_summ_nth_elem(sequence, 5);
    ASSERT_EQ(index, 3);
}

TEST(MaxSumNthElemIndex, ForGeometrics2) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(5, 4));
    sequence.insert(make_shared<GeometricSequance>(7, 4));
    sequence.insert(make_shared<GeometricSequance>(2, 9));
    sequence.insert(make_shared<GeometricSequance>(4, 3));
    const auto index = max_summ_nth_elem(sequence, 2);
    ASSERT_EQ(index, 1);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics1) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(1, 2));
    sequence.insert(make_shared<ArithmeticSequance>(2, 8));
    sequence.insert(make_shared<GeometricSequance>(3, 6));
    sequence.insert(make_shared<ArithmeticSequance>(6, 18));
    const auto index = max_summ_nth_elem(sequence, 9);
    ASSERT_EQ(index, 2);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics2) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(2, 4));
    sequence.insert(make_shared<ArithmeticSequance>(1, 10));
    sequence.insert(make_shared<ArithmeticSequance>(1, 5));
    sequence.insert(make_shared<ArithmeticSequance>(8, 20));
    const auto index = max_summ_nth_elem(sequence, 1);
    ASSERT_EQ(index, 3);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics3) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(7, 14));
    sequence.insert(make_shared<ArithmeticSequance>(2, 5));
    sequence.insert(make_shared<GeometricSequance>(6, 12));
    sequence.insert(make_shared<GeometricSequance>(1, 8));
    const auto index = max_summ_nth_elem(sequence, 4);
    ASSERT_EQ(index, 0);
   
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics4) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(1, 4));
    sequence.insert(make_shared<ArithmeticSequance>(2, 4));
    sequence.insert(make_shared<GeometricSequance>(2, 4));
    sequence.insert(make_shared<GeometricSequance>(1, 8));
    sequence.insert(make_shared<GeometricSequance>(3, 9));
    sequence.insert(make_shared<ArithmeticSequance>(3, 13));
    sequence.insert(make_shared<GeometricSequance>(3, 16));
    sequence.insert(make_shared<GeometricSequance>(8, 16));
    const auto index = max_summ_nth_elem(sequence, 10);
    ASSERT_EQ(index, 7);
}

TEST(MaxSumNthElemIndex, ArithmeticsAndGeometrics5) {
    SequanceContainer sequence;
    sequence.insert(make_shared<GeometricSequance>(6, 12));
    sequence.insert(make_shared<ArithmeticSequance>(3, 7));
    sequence.insert(make_shared<GeometricSequance>(4, 12));
    sequence.insert(make_shared<GeometricSequance>(6, 9));
    sequence.insert(make_shared<GeometricSequance>(7, 14));
    sequence.insert(make_shared<ArithmeticSequance>(5, 10));
    sequence.insert(make_shared<GeometricSequance>(1, 10));
    sequence.insert(make_shared<GeometricSequance>(8, 16));
    sequence.insert(make_shared<GeometricSequance>(6, 9));
    sequence.insert(make_shared<GeometricSequance>(8, 16));
    const auto index = max_summ_nth_elem(sequence, 4);
    ASSERT_EQ(index, 9);
}