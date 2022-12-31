#include <gtest/gtest.h>
#include <vector>

#include "reverse_vector.h"

TEST(ReverseCopy, VectorIntNonempty) {
    std::vector<int> input{1, 3, 5, 7, 9}, expected{9, 7, 5, 3, 1};
    EXPECT_EQ(reverse_copy(input), expected);
}

TEST(ReverseCopy, VectorIntEmpty) {
    std::vector<int> input;
    EXPECT_TRUE(reverse_copy(input).empty());
}

TEST(ReverseInplace, VectorIntNonempty) {
    std::vector<int> input{1, 3, 5, 7, 9}, expected{9, 7, 5, 3, 1};
    reverse_in_place(input);
    EXPECT_EQ(input, expected);
}

TEST(ReverseInplace, VectorIntEmpty) {
    std::vector<int> input, expected;
    reverse_in_place(input);
    EXPECT_EQ(input, expected);
}

TEST(ReverseCopy, VectorStringNonempty) {
    std::vector<std::string> input{"foo", "bar", "baz", "qux"}, expected{"qux", "baz", "bar", "foo"};
    EXPECT_EQ(reverse_copy(input), expected);
}

TEST(ReverseCopy, VectorStringEmpty) {
    std::vector<std::string> input;
    EXPECT_TRUE(reverse_copy(input).empty());
}

TEST(ReverseInplace, VectorStringNonempty) {
    std::vector<std::string> input{"foo", "bar", "baz", "qux"}, expected{"qux", "baz", "bar", "foo"};
    reverse_in_place(input);
    EXPECT_EQ(input, expected);
}

TEST(ReverseInplace, VectorStringEmpty) {
    std::vector<std::string> input, expected;
    reverse_in_place(input);
    EXPECT_EQ(input, expected);
}
