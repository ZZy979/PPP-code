#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>

#include "solve_equation.h"

TEST(SolveQuadraticEquation, TwoDifferentRoots) {
    auto p = solve_quadratic_equation(2, 6, -3);
    EXPECT_DOUBLE_EQ(p.first, (-3 + sqrt(15)) / 2);
    EXPECT_DOUBLE_EQ(p.second, (-3 - sqrt(15)) / 2);
}

TEST(SolveQuadraticEquation, TwoSameRoots) {
    auto p = solve_quadratic_equation(1, 4, 4);
    EXPECT_DOUBLE_EQ(p.first, -2);
    EXPECT_DOUBLE_EQ(p.second, -2);
}

TEST(SolveQuadraticEquation, NoRealRoots) {
    EXPECT_THROW(solve_quadratic_equation(-3, 5, -4), std::invalid_argument);
}
