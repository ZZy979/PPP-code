#include <gtest/gtest.h>

#include "string_algorithm_exec18.h"

TEST(StringAlgorithmExec18Test, Strdup) {
    char test_cases[][50] = {"Hello, world!", "ABCabc123!@#\n\t", ""};
    for (const char* s : test_cases) {
        char* t = strdup_(s);
        EXPECT_STREQ(t, s);
        delete[] t;
    }
}

TEST(StringAlgorithmExec18Test, Findx) {
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

TEST(StringAlgorithmExec18Test, Strcmp) {
    struct Test_case {
        char s[20];
        char t[20];
        int expected;
    } test_cases[] = {
        {"abc", "abd", -1},
        {"abc", "abcd", -1},
        {"abc", "abc", 0},
        {"abc", "abC", 1},
        {"abc", "a", 1},
        {"", "abc", -1},
        {"abc", "", 1},
        {"", "", 0}
    };
    for (const Test_case& t : test_cases) {
        int res = strcmp_(t.s, t.t);
        if (t.expected < 0)
            EXPECT_LT(res, 0);
        else if (t.expected > 0)
            EXPECT_GT(res, 0);
        else
            EXPECT_EQ(res, 0);
    }
}

TEST(StringAlgorithmExec18Test, CatDot) {
    struct Test_case {
        std::string s1;
        std::string s2;
        std::string separator;
        std::string expected;
    } test_cases[] = {
        {"Niels", "Bohr", "", "Niels.Bohr"},
        {"Tom", "Jerry", "&", "Tom&Jerry"},
        {"bob", "example.com", "@", "bob@example.com"},
        {"aaaaa", "bbbb", "###", "aaaaa###bbbb"}
    };
    for (const Test_case& t : test_cases) {
        EXPECT_EQ(t.separator.empty() ? cat_dot(t.s1, t.s2) : cat_dot(t.s1, t.s2, t.separator), t.expected);

        char* r = t.separator.empty() ? cat_dot(t.s1.c_str(), t.s2.c_str())
                : cat_dot(t.s1.c_str(), t.s2.c_str(), t.separator.c_str());
        EXPECT_STREQ(r, t.expected.c_str());
        delete[] r;
    }
}
