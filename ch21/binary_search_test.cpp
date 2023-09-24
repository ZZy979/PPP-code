#include <gtest/gtest.h>
#include <list>
#include <string>
#include <vector>

#include "binary_search.h"

TEST(BinarySearch, Vector) {
    std::vector<int> v0, v1 = {0, 10}, v2 = {2, 10, 18, 22, 22, 24, 30, 35};

    struct Test_case {
        const std::vector<int>& v;
        int value;
        bool expected;
    } test_cases[] = {
        {v0, 24, false},
        {v1, -1, false},
        {v1, 0, true},
        {v1, 5, false},
        {v1, 10, true},
        {v1, 20, false},
        {v2, 0, false},
        {v2, 2, true},
        {v2, 22, true},
        {v2, 24, true},
        {v2, 26, false},
        {v2, 35, true},
        {v2, 50, false}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(my_binary_search(t.v.begin(), t.v.end(), t.value), t.expected);
}

TEST(BinarySearch, List) {
    std::list<std::string> l0, l = {"apple", "apple", "banana", "cat", "cat", "dog", "dog", "dog"};

    struct Test_case {
        const std::list<std::string>& l;
        const std::string& value;
        bool expected;
    } test_cases[] = {
        {l0, "hello", false},
        {l, "", false},
        {l, "apple", true},
        {l, "boy", false},
        {l, "dog", true},
        {l, "hello", false}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(my_binary_search(t.l.begin(), t.l.end(), t.value), t.expected);
}
