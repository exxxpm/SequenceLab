#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace sequence;

TEST(SequenceTests, ArithmeticTest) {
    SequanceItem tests_arithm(SequanceItemType::ARITHMETIC, 1, 2, 0);
    int result = tests_arithm.calc_nth_elem(10);
    EXPECT_EQ(result, 19);
}

TEST(SequenceTests, GeometricTest) {
    SequanceItem tests_geom(SequanceItemType::GEOMETRIC, 2, 0, 2);
    int result = tests_geom.calc_nth_elem(7);
    EXPECT_EQ(result, 128);
}