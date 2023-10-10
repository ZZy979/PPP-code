#include <gtest/gtest.h>

#include "string_convert.h"

TEST(StringConvert, ToString) {
    EXPECT_EQ(to_string(12.333), "12.333");
    EXPECT_EQ(to_string(1 + 5 * 6 - 99 / 7), "17");
    EXPECT_EQ(to_string('@'), "@");
    EXPECT_EQ(to_string("hello"), "hello");
}

TEST(StringConvert, FromString) {
    EXPECT_DOUBLE_EQ(from_string<double>("12.333"), 12.333);
    EXPECT_EQ(from_string<int>(" 42 "), 42);
    EXPECT_EQ(from_string<int>("12.333"), 12);
    EXPECT_THROW(from_string<int>("Mary had a little lamb"), bad_from_string);
    EXPECT_EQ(from_string<char>("abc"), 'a');
    EXPECT_EQ(from_string<std::string>("hello world"), "hello");
}

TEST(StringConvert, To) {
    EXPECT_EQ(to<int>("123"), 123);
    EXPECT_EQ(to<int>("123  "), 123);
    EXPECT_THROW(to<int>("123 5"), std::bad_cast);
    EXPECT_THROW(to<int>("123.5"), std::bad_cast);
    EXPECT_DOUBLE_EQ(to<double>("123.5"), 123.5);

    EXPECT_EQ(to<std::string>(1024), "1024");
    EXPECT_EQ(to<std::string>(-2.5496e3), "-2549.6");

    EXPECT_THROW(to<int>(123.5), std::bad_cast);
    EXPECT_DOUBLE_EQ(to<double>(42), 42.0);

    EXPECT_THROW(to<int>('A'), std::bad_cast);
    EXPECT_EQ(to<int>('8'), 8);
    EXPECT_THROW(to<char>(100), std::bad_cast);
    EXPECT_EQ(to<char>(9), '9');
}
