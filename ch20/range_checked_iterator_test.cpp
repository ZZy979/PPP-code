#include <algorithm>
#include <gtest/gtest.h>

#include "range_checked_iterator.h"

class RangeCheckedIteratorTest : public ::testing::Test {
protected:
    std::vector<int> vec_ = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> list_ = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

TEST_F(RangeCheckedIteratorTest, Vector) {
    auto begin = range_checked_begin(vec_), end = range_checked_end(vec_);
    EXPECT_EQ(end - begin, 10);

    auto p = begin + 6;
    EXPECT_EQ(*p, 6);
    ++p;
    EXPECT_EQ(*p, 7);
    p += 10;
    EXPECT_THROW(*p, std::out_of_range);

    auto q = std::find(begin, end, 5);
    EXPECT_NE(q, end);
    EXPECT_EQ(*q, 5);

    EXPECT_TRUE(std::equal(begin, end, list_.begin()));
}

TEST_F(RangeCheckedIteratorTest, List) {
    auto begin = range_checked_begin(list_), end = range_checked_end(list_);
    EXPECT_EQ(std::distance(begin, end), 10);

    auto p = std::next(begin, 6);
    EXPECT_EQ(*p, 6);
    ++p;
    EXPECT_EQ(*p, 7);
    EXPECT_THROW(std::advance(p, 10), std::out_of_range);

    auto q = std::find(begin, end, 5);
    EXPECT_NE(q, end);
    EXPECT_EQ(*q, 5);

    EXPECT_TRUE(std::equal(begin, end, vec_.begin()));
}
