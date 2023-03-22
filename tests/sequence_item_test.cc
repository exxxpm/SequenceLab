#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace sequence;

TEST(SequanceItemTests, CalcNthElemArithmeticTest1) {
    SequanceItem tests_arithm(SequanceItemType::ARITHMETIC, 1, 2, 0);
    int result = tests_arithm.calc_nth_elem(12);
    EXPECT_EQ(result, 23);
}

TEST(SequanceItemTests, CalcNthElemArithmeticTest2) {
    SequanceItem tests_arithm(SequanceItemType::ARITHMETIC, 3, 9, 0);
    int result = tests_arithm.calc_nth_elem(10);
    EXPECT_EQ(result, 84);
}

TEST(SequanceItemTests, CalcNthElemGeometricTest1) {
    SequanceItem tests_geom(SequanceItemType::GEOMETRIC, 1, 0, 3);
    int result = tests_geom.calc_nth_elem(2);
    EXPECT_EQ(result, 3);
}

TEST(SequanceItemTests, CalcNthElemGeometricTest2) {
    SequanceItem tests_geom(SequanceItemType::GEOMETRIC, 2, 0, 6);
    int result = tests_geom.calc_summ_nth_elem(1);
    EXPECT_EQ(result, 2);
}

TEST(SequanceItemTests, CalcSummNthElemArithmeticTest1) {
    SequanceItem tests_arithm(SequanceItemType::ARITHMETIC, 3, 6, 0);
    int result = tests_arithm.calc_summ_nth_elem(1);
    EXPECT_EQ(result, 3);
}

TEST(SequanceItemTests, CalcSummNthElemArithmeticTest2) {
    SequanceItem tests_arithm(SequanceItemType::ARITHMETIC, 8, 16, 0);
    int result = tests_arithm.calc_summ_nth_elem(4);
    EXPECT_EQ(result, 128);
}

TEST(SequanceItemTests, CalcSummNthElemGeometricTest1) {
    SequanceItem tests_geom(SequanceItemType::GEOMETRIC, 5, 0, 10);
    int result = tests_geom.calc_summ_nth_elem(2);
    EXPECT_EQ(result, 55);
}

TEST(SequanceItemTests, CalcSummNthElemGeometricTest2) {
    SequanceItem tests_geom(SequanceItemType::GEOMETRIC, 6, 0, 9);
    int result = tests_geom.calc_summ_nth_elem(3);
    EXPECT_EQ(result, 546);
}
