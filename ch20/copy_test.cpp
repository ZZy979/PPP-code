#include <algorithm>
#include <gtest/gtest.h>
#include <vector>

#include "copy.h"

TEST(CopyTest, IntArray) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b[] = {111, 222, 333, 444, 555}, c[10];
    my_copy(a, a + 10, c);
    EXPECT_TRUE(std::equal(a, a + 10, c));
    my_copy(b, b + 5, c);
    EXPECT_TRUE(std::equal(b, b + 5, c));
}

TEST(CopyTest, IntVector) {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b = {111, 222, 333, 444, 555}, c(10);
    my_copy(&a[0], &a[0] + a.size(), &c[0]);
    EXPECT_TRUE(std::equal(&a[0], &a[0] + a.size(), &c[0]));
    my_copy(&b[0], &b[0] + b.size(), &c[0]);
    EXPECT_TRUE(std::equal(&b[0], &b[0] + b.size(), &c[0]));
}

TEST(CopyTest, VectorToArray) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    int b[10];
    auto p = my_copy(a.begin(), a.end(), b);
    EXPECT_EQ(p, b + 5);
    EXPECT_TRUE(std::equal(a.begin(), a.end(), b));
}
