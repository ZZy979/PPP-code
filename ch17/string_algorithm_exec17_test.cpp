#include <gtest/gtest.h>

#include "string_algorithm_exec17.h"

TEST(StringAlgorithmExec17Test, ToLower) {
    struct Test_case {
        char s[50];
        char expected[50];
    } test_cases[] = {
        {"Hello, world!", "hello, world!"},
        {"ABCabc123!@#\n\t", "abcabc123!@#\n\t"},
        {"", ""}
    };
    for (Test_case t : test_cases) {
        to_lower(t.s);
        EXPECT_STREQ(t.s, t.expected);
    }
}

TEST(StringAlgorithmExec17Test, Strdup) {
    char test_cases[][50] = {"Hello, world!", "ABCabc123!@#\n\t", ""};
    for (const char* s : test_cases) {
        char* t = strdup_(s);
        EXPECT_STREQ(t, s);
        delete[] t;
    }
}

TEST(StringAlgorithmExec17Test, Findx) {
    struct Test_case {
        char s[50];
        char x[50];
        int expected;
    } test_cases[] = {
        {"annbcdanacadsannannacannadcaba", "annacanna", 16},
        {"height right light", "ight", 2},
        {"hello, world!", "world!", 7},
        {"hello, world!", "hello", 0},
        {"hello", "abc", -1},
        {"hello", "", -1},
        {"", "abc", -1},
        {"", "", -1}
    };
    for (const Test_case& t : test_cases)
        EXPECT_EQ(findx(t.s, t.x), t.expected == -1 ? nullptr : t.s + t.expected);
}
