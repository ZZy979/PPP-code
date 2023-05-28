#include <gtest/gtest.h>

#include "palindrome.h"

struct Test_case {
    std::string s;
    bool expected;
};

const Test_case test_cases[] = {
    {"", true},
    {"a", true},
    {"aa", true},
    {"ab", false},
    {"anna", true},
    {"petep", true},
    {"malayalam", true},
    {"ida", false},
    {"homesick", false}
};

TEST(IsPalindromeTest, StringVersion) {
    for (const Test_case& t : test_cases) {
        EXPECT_EQ(is_palindrome(t.s), t.expected);
        EXPECT_EQ(is_palindrome2(t.s), t.expected);
    }
}

TEST(IsPalindromeTest, ArrayVersion) {
    for (const Test_case& t : test_cases) {
        EXPECT_EQ(is_palindrome(t.s.c_str(), t.s.length()), t.expected);
        EXPECT_EQ(is_palindrome2(t.s.c_str(), t.s.length()), t.expected);
    }
}

TEST(IsPalindromeTest, PointerVersion) {
    for (const Test_case& t : test_cases) {
        EXPECT_EQ(is_palindrome(t.s.c_str(), t.s.c_str() + t.s.length() - 1), t.expected);
        EXPECT_EQ(is_palindrome2(t.s.c_str(), t.s.c_str() + t.s.length() - 1), t.expected);
    }
}
