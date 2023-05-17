#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace sequence;
using namespace std;

TEST(SequanceItemTests, CalcNthElemArithmeticTest1) {
    const auto tests_arithm = make_shared<ArithmeticSequance>(1, 2);
    int result = tests_arithm->calc_nth_elem(12);
    EXPECT_EQ(result, 23);
}

TEST(SequanceItemTests, CalcNthElemArithmeticTest2) {
    const auto tests_arithm = make_shared<ArithmeticSequance>(3, 9);
    int result = tests_arithm->calc_nth_elem(10);
    EXPECT_EQ(result, 84);
}

TEST(SequanceItemTests, CalcNthElemGeometricTest1) {
    const auto tests_arithm = make_shared<GeometricSequance>(1, 3);
    int result = tests_arithm->calc_nth_elem(2);
    EXPECT_EQ(result, 3);
}

TEST(SequanceItemTests, CalcNthElemGeometricTest2) {
    const auto tests_arithm = make_shared<GeometricSequance>(2, 6);
    int result = tests_arithm->calc_summ_nth_elem(1);
    EXPECT_EQ(result, 2);
}

TEST(SequanceItemTests, CalcSummNthElemArithmeticTest1) {
    const auto tests_arithm = make_shared<ArithmeticSequance>(3, 6);
    int result = tests_arithm->calc_summ_nth_elem(1);
    EXPECT_EQ(result, 3);
}

TEST(SequanceItemTests, CalcSummNthElemArithmeticTest2) {
    const auto tests_arithm = make_shared<ArithmeticSequance>(8, 16);
    int result = tests_arithm->calc_summ_nth_elem(4);
    EXPECT_EQ(result, 128);
}

TEST(SequanceItemTests, CalcSummNthElemGeometricTest1) {
    const auto tests_arithm = make_shared<GeometricSequance>(5, 10);
    int result = tests_arithm->calc_summ_nth_elem(2);
    EXPECT_EQ(result, 55);
}

TEST(SequanceItemTests, CalcSummNthElemGeometricTest2) {
    const auto tests_arithm = make_shared<GeometricSequance>(6, 9);
    int result = tests_arithm->calc_summ_nth_elem(3);
    EXPECT_EQ(result, 546);
}
