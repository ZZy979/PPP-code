#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>

#include "fibonacci.h"

TEST(Fibonacci, Normal) {
    std::vector<int> expected{1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    std::vector<int> actual;
    fibonacci(1, 1, actual, 10);
    EXPECT_EQ(actual, expected);
}

TEST(Fibonacci, NIsNegative) {
    std::vector<int> actual;
    EXPECT_THROW(fibonacci(1, 1, actual, -2), std::invalid_argument);
}

TEST(Fibonacci, NIsZero) {
    std::vector<int> actual;
    fibonacci(1, 1, actual, 0);
    EXPECT_TRUE(actual.empty());
}

TEST(Fibonacci, NIsOne) {
    std::vector<int> expected{3}, actual;
    fibonacci(3, 5, actual, 1);
    EXPECT_EQ(actual, expected);
}

TEST(Fibonacci, DifferentStart) {
    std::vector<int> expected{4, 7, 11, 18, 29, 47, 76, 123, 199, 322};
    std::vector<int> actual;
    fibonacci(4, 7, actual, 10);
    EXPECT_EQ(actual, expected);
}

TEST(Fibonacci, IntMax) {
    std::vector<int> actual;
    fibonacci(1, 1, actual, 47);
    EXPECT_EQ(actual[45], 1836311903);
    EXPECT_EQ(actual[46], -1323752223);
}
