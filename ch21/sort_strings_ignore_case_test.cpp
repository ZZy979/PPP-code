#include <algorithm>
#include <gtest/gtest.h>

#include "sort_strings_ignore_case.h"

TEST(SortStringsIgnoreCaseTest, Test) {
    struct Test_case {
        std::vector<std::string> v, expected;
    } test_cases[] = {
        {{}, {}},
        {{"Cat", "apple", "dog", "Banana"}, {"apple", "Banana", "Cat", "dog"}},
        {{"The", "MAN", "bit", "the", "DOG"}, {"bit", "DOG", "MAN", "The", "the"}},
        {{"Beta", "gamma", "ALPHA", "delta"}, {"ALPHA", "Beta", "delta", "gamma"}}
    };

    for (const auto& t : test_cases) {
        std::vector<std::string> v1 = t.v;
        sort_strings_ignore_case(v1);
        EXPECT_EQ(v1, t.expected);

        std::vector<std::string> v2 = t.v;
        sort_strings_ignore_case2(v2);
        EXPECT_EQ(v2, t.expected);
    }
}
