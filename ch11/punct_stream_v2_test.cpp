#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

#include "punct_stream_v2.h"

TEST(HelperFunctionTest, Replace) {
    struct Test_case {
        std::string s;
        std::string from;
        std::string to;
        std::string expected;
    } test_cases[] = {
        {"from to today potato", "to", "TO", "from TO TOday potaTO"},
        {"abcabc", "a", "aa", "aabcaabc"},
        {"abcabc", "b", "b", "abcabc"},
        {"", "a", "aa", ""},
        {"abcabc", "a", "", "bcbc"},
        {"abcabc", "", "d", "abcabc"},
        {"abcabc", "", "", "abcabc"},
        {"abcabc", "d", "dd", "abcabc"},
        {"aaa", "a", "aa", "aaaaaa"},
        {"|a|b|c|", "|", "|d|", "|d|a|d|b|d|c|d|"}
    };
    for (Test_case t : test_cases) {
        replace(t.s, t.from, t.to);
        EXPECT_EQ(t.s, t.expected);
    }
}

TEST(HelperFunctionTest, IsHyphenWithinWords) {
    struct Test_case {
        std::string s;
        int i;
        bool expected;
    } test_cases[] = {
        {"as-if", 2, true},
        {"as-if", 1, false},
        {"as- if", 3, false},
        {"as -if", 3, false},
        {"as - if", 3, false},
        {"as--if", 3, false},
        {"as.-if", 3, false}
    };
    for (const Test_case& t : test_cases)
        EXPECT_EQ(is_hyphen_within_words(t.s, t.i), t.expected);
}

class PunctStreamV2Test : public ::testing::Test {
protected:
    PunctStreamV2Test() :ps_(iss_, {{"don't", "do not"}, {"can't", "can not"}}) {}

    Punct_stream_v2 ps_;
    std::istringstream iss_;
};

TEST_F(PunctStreamV2Test, InputOperator) {
    ps_.whitespace(";:,.?-'");
    iss_.str(
            "To be, or not to be.\n"
            "  I can't know!\n"
            "Don't you?\n"
            " \t\n"
            ":foo,,bar...baz 'qux';\n"
            "- don't use the as-if rule.\n"
            "no newline at end");

    std::vector<std::string> v, expected{
        "To", "be", "or", "not", "to", "be",
        "I", "can", "not", "know!",
        "Don", "t", "you",
        "foo", "bar", "baz", "qux",
        "do", "not", "use", "the", "as-if", "rule",
        "no", "newline", "at", "end"
    };
    for (std::string word; ps_ >> word;)
        v.push_back(word);
    EXPECT_EQ(v, expected);
}

TEST_F(PunctStreamV2Test, CaseSensitive) {
    ps_.whitespace(";:,.?-'");
    ps_.case_sensitive(false);
    iss_.str("AS-IF rule.\nDon't you?\n");

    std::vector<std::string> v, expected{"as-if", "rule", "do", "not", "you"};
    for (std::string word; ps_ >> word;)
        v.push_back(word);
    EXPECT_EQ(v, expected);
}
