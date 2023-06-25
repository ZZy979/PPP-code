#include <gtest/gtest.h>
#include <string>

#include "vector_add.h"

TEST(VectorAddTest, SameSize) {
    std::vector<int> vi1{1, 2, 3, 4, 5}, vi2{10, 20, 30, 40, 50}, expected_vi{11, 22, 33, 44, 55};
    add(vi1, vi2);
    EXPECT_EQ(vi1, expected_vi);

    std::vector<std::string> vs1{"A", "B", "C"}, vs2{"a", "b", "c"}, expected_vs{"Aa", "Bb", "Cc"};
    add(vs1, vs2);
    EXPECT_EQ(vs1, expected_vs);
}

TEST(VectorAddTest, DifferentSize) {
    std::vector<int> v1{1, 2, 3, 4, 5}, v2{10, 20, 30};
    EXPECT_THROW(add(v1, v2), std::invalid_argument);
}

TEST(VectorAddTest, Empty) {
    std::vector<int> v1, v2;
    add(v1, v2);
    EXPECT_TRUE(v1.empty());
}
