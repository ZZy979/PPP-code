#include <gtest/gtest.h>

#include "factorial.h"

TEST(FactorialTest, Result) {
    struct Test_case {
        int n;
        long long expected;
    } test_cases[] = {
        {0, 1}, {1, 1}, {3, 6}, {9, 362880}, {20, 2432902008176640000LL}
    };
    for (const Test_case& t : test_cases) {
        EXPECT_EQ(factorial_iterative(t.n), t.expected);
        EXPECT_EQ(factorial_recursive(t.n), t.expected);
    }
}

TEST(FactorialTest, SameResults) {
    for (int n = 0; n <= 20; ++n)
        EXPECT_EQ(factorial_iterative(n), factorial_recursive(n));
}
