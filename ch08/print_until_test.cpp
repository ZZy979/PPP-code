#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

#include "print_until.h"

TEST(PrintUntil, FirstOccurrence) {
    std::string quit = "q";
    std::vector<std::pair<std::vector<std::string>, std::string>> test_cases = {
        {{"a", "b", "c", "q", "d"}, "a\nb\nc\n"},
        {{"a", "q", "b", "q", "c"}, "a\n"},
        {{"q", "a", "b"}, ""},
        {{"a", "b", "c", "d"}, "a\nb\nc\nd\n"},
        {{}, ""}
    };
    for (const auto& t : test_cases) {
        std::ostringstream oss;
        print_until_s(t.first, quit, oss);
        EXPECT_EQ(oss.str(), t.second);
    }
}

TEST(PrintUntil, SecondOccurrence) {
    std::string quit = "q";
    std::vector<std::pair<std::vector<std::string>, std::string>> test_cases = {
        {{"a", "b", "c", "q", "d"}, "a\nb\nc\nq\nd\n"},
        {{"a", "q", "b", "q", "c"}, "a\nq\nb\n"},
        {{"q", "q", "a", "b"}, "q\n"},
        {{"q", "a", "b"}, "q\na\nb\n"},
        {{"a", "b", "c", "d"}, "a\nb\nc\nd\n"},
        {{}, ""}
    };
    for (const auto& t : test_cases) {
        std::ostringstream oss;
        print_until_ss(t.first, quit, oss);
        EXPECT_EQ(oss.str(), t.second);
    }
}
