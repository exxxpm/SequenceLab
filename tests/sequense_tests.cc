#include <gtest/gtest.h>

#include <sequance/sequance.h>

TEST(sequanceTests, SumStubTest1) {
    // Arrange
    int lhs = 2;
    int rhs = 3;

    // Act
    int r = sum_stub(lhs, rhs);

    // Assert
    EXPECT_EQ(r, 5);
}

TEST(sequanceTests, SumStubTest2) {
    // Arrange
    int lhs = -1;
    int rhs = 3;

    // Act
    int r = sum_stub(lhs, rhs);

    // Assert
    EXPECT_EQ(r, 2);
}
