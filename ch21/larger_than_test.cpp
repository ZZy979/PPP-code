#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

#include "larger_than.h"

TEST(LargerThanTest, Call) {
    EXPECT_TRUE(Larger_than(31)(42));
    EXPECT_FALSE(Larger_than(42)(31));
}

TEST(LargetThanTest, FindIf) {
    std::vector<int> v = {1, 2, 3, 4, 5};

    auto p = std::find_if(v.begin(), v.end(), Larger_than(42));
    EXPECT_EQ(p, v.end());

    p = std::find_if(v.begin(), v.end(), Larger_than(3));
    EXPECT_NE(p, v.end());
    EXPECT_GT(*p, 3);
}
