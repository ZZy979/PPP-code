#include <gtest/gtest.h>

#include "swaps.h"

TEST(SwapsTest, Int) {
    int x = 7, y = 9;

    swap_v(x, y);
    EXPECT_EQ(x, 7);
    EXPECT_EQ(y, 9);

    swap_r(x, y);
    EXPECT_EQ(x, 9);
    EXPECT_EQ(y, 7);
}

TEST(SwapsTest, ConstInt) {
    const int cx = 7, cy = 9;

    swap_v(cx, cy);
    EXPECT_EQ(cx, 7);
    EXPECT_EQ(cy, 9);

    // 编译错误 error: binding reference of type 'int&' to 'const int' discards qualifiers
    // swap_r(cx, cy);
}

TEST(SwapsTest, Double) {
    double dx = 7.7, dy = 9.9;

    swap_v(dx, dy);
    EXPECT_DOUBLE_EQ(dx, 7.7);
    EXPECT_DOUBLE_EQ(dy, 9.9);

    // 编译错误 error: cannot bind non-const lvalue reference of type 'int&' to a value of type 'double'
    // swap_r(dx, dy);
}
