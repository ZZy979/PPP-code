#include <gtest/gtest.h>

#include <cstdint>
#include <stdexcept>

#include "relational.h"

using R = Relational;

TEST(RelationalTest, Constructor) {
    struct Test_case {
        int64_t numerator;
        int64_t denominator;
        int64_t expected_numerator;
        int64_t expected_denominator;
    } test_cases[] = {
        {5, 6, 5, 6},
        {2, 4, 1, 2},
        {0, 2, 0, 1},
        {21, -35, -3, 5},
        {-0xFFFFFFFFLL, 0x100000001LL, -0xFFFFFFFFLL, 0x100000001LL},
        {-142857, -999999, 1, 7}
    };
    for (const auto& t : test_cases) {
        R r(t.numerator, t.denominator);
        EXPECT_EQ(r.num(), t.expected_numerator);
        EXPECT_EQ(r.den(), t.expected_denominator);
    }

    R r = 8;
    EXPECT_EQ(r.num(), 8);
    EXPECT_EQ(r.den(), 1);

    EXPECT_THROW(R(1, 0), std::invalid_argument);
}

TEST(RelationalTest, Assignment) {
    R a(6, 5), b(2, 3);
    EXPECT_EQ(a.num(), 6);
    EXPECT_EQ(a.den(), 5);
    a = b;
    EXPECT_EQ(a.num(), 2);
    EXPECT_EQ(a.den(), 3);
}

TEST(RelationalTest, Addition) {
    struct Test_case {
        R a;
        R b;
        R sum;
    } test_cases[] = {
        {{1, 3}, {1, 6}, {1, 2}},
        {{5, 6}, {1, 12}, {11, 12}},
        {{4, 3}, {-1, 5}, {17, 15}},
        {-2, {5, 9}, {-13, 9}},
        {{-1, 4}, {-1, 3}, {-7, 12}},
        {0, {2, 7}, {2, 7}},
        {{-4, 9}, {4, 9}, 0}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(t.a + t.b, t.sum);
    }
}

TEST(RelationalTest, Subtraction) {
    struct Test_case {
        R a;
        R b;
        R difference;
    } test_cases[] = {
        {{2, 5}, {1, 2}, {-1, 10}},
        {{6, 25}, {8, 9}, {-146, 225}},
        {{3, 4}, {2, 3}, {1, 12}},
        {{21, 26}, {5, 9}, {59, 234}},
        {{5, 7}, {7, 5}, {-24, 35}},
        {0, {2, 15}, {-2, 15}},
        {{7, 13}, 0, {7, 13}}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(t.a - t.b, t.difference);
    }
}

TEST(RelationalTest, Multiplication) {
    struct Test_case {
        R a;
        R b;
        R product;
    } test_cases[] = {
        {{1, 2}, {1, 3}, {1, 6}},
        {{2, 5}, {3, 7}, {6, 35}},
        {{4, 5}, {5, 18}, {2, 9}},
        {{-2, 3}, 6, -4},
        {{5, 18}, {-27, 40}, {-3, 16}},
        {0, {1, 4}, 0},
        {{-3, 5}, 0, 0},
        {1, {3, 8}, {3, 8}}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(t.a * t.b, t.product);
    }
}

TEST(RelationalTest, Division) {
    struct Test_case {
        R a;
        R b;
        R quotient;
    } test_cases[] = {
        {{5, 6}, {1, 8}, {20, 3}},
        {{-15, 32}, {-5, 8}, {3, 4}},
        {{-5, 9}, {2, 3}, {-5, 6}},
        {{17, 24}, -5, {-17, 120}},
        {142857, 999999, {1, 7}},
        {0, {9, 13}, 0},
        {1, {5, 12}, {12, 5}},
        {{13, 8}, 1, {13, 8}}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(t.a / t.b, t.quotient);
    }

    EXPECT_THROW(R(4, 7) / R(0), std::invalid_argument);
}

TEST(RelationalTest, MixedExpression) {
    struct Test_case {
        R actual;
        R expected;
    } test_cases[] = {
        {R(3, 10) * (R(1, 2) + R(1, 3)) / R(1, 8), 2},
        {R(7, 8) / (R(7, 8) - R(3, 4)) * R(4, 5), R(28, 5)},
        {R(6) * (R(2, 15) + R(1, 12)) - R(1, 8), R(47, 40)},
        {R(2) - R(5, 9) / R(2, 3) - R(1, 6), 1},
        {R(7, 3) - (R(3, 5) / R(9, 20) + R(8, 23)), R(15, 23)},
        {(R(2) - (R(8, 5) + R(1, 3))) / R(4, 15), R(1, 4)}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(t.actual, t.expected);
    }
}

TEST(RelationalTest, CastToDouble) {
    struct Test_case {
        R a;
        double expected;
    } test_cases[] = {
        {R(1, 3), 1.0 / 3},
        {-R(2, 5), -0.4},
        {R(-17, 25), -0.68},
        {R(37, -15), -37.0 / 15},
        {R(8), 8}
    };
    for (const auto& t : test_cases) {
        EXPECT_DOUBLE_EQ(double(t.a), t.expected);
    }
}
