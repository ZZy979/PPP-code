#include <gtest/gtest.h>
#include <list>
#include <string>
#include <vector>

#include "count.h"

TEST(CountTest, Count) {
    int a[] = {1, 1, 2, 3, 3, 3, 3, 4, 4, 4};
    EXPECT_EQ(my_count(a, a + 10, 3), 4);
    EXPECT_EQ(my_count(a, a + 10, 2), 1);
    EXPECT_EQ(my_count(a, a + 10, 5), 0);

    std::vector<std::string> v = {"To", "be", "or", "not", "to", "be"};
    EXPECT_EQ(my_count(v.begin(), v.end(), "to"), 1);
    EXPECT_EQ(my_count(v.begin(), v.end(), "be"), 2);
    EXPECT_EQ(my_count(v.begin(), v.end(), "is"), 0);
}

TEST(CountTest, CountIf) {
    std::vector<int> v = {48, 74, 58, 13, 65, 22, 89, 24, 28, 93};
    EXPECT_EQ(my_count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), 6);
    EXPECT_EQ(my_count_if(v.begin(), v.end(), [](int x) { return x > 50; }), 5);

    std::list<std::string> l = {
        "apple", "banana", "car", "dog", "education", "football", "guitar", "house", "internet", "jacket",
        "kangaroo", "laptop", "music", "notebook", "ocean", "pizza", "quartz", "rainbow", "sun", "tree"
    };
    EXPECT_EQ(my_count_if(l.begin(), l.end(), [](const std::string& s) { return s.length() >= 7; }), 6);
    EXPECT_EQ(my_count_if(l.begin(), l.end(), [](const std::string& s) { return s.find('a') != std::string::npos; }), 13);
}
