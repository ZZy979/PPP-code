#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "split.h"

TEST(SplitTest, DefaultWhitespace) {
    struct Test_case {
        std::string s;
        std::vector<std::string> expected;
    } test_cases[] = {
        {"ab cd  ef\tgh\r\nij\f\vkl", {"ab", "cd", "ef", "gh", "ij", "kl"}},
        {"  abc def\t\t", {"abc", "def"}},
        {"    ", {}},
        {"", {}}
    };
    for (const Test_case& t : test_cases) {
        std::vector<std::string> actual;
        split(t.s, actual);
        EXPECT_EQ(actual, t.expected);
    }
}

TEST(SplitTest, CustomWhitespace) {
    struct Test_case {
        std::string s;
        std::string whitespaces;
        std::vector<std::string> expected;
    } test_cases[] = {
        {"ab cd-ef,gh|ij..kl", ",.", {"ab", "cd-ef", "gh|ij", "kl"}},
        {"[abc(def)](ghi)", "()[]", {"abc", "def", "ghi"}},
        {";;;;", ";", {}},
        {"", ";", {}}
    };
    for (const Test_case& t : test_cases) {
        std::vector<std::string> actual;
        split(t.s, t.whitespaces, actual);
        EXPECT_EQ(actual, t.expected);
    }
}
