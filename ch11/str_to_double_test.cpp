#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

#include "str_to_double.h"

TEST(StrToDoubleTest, Valid) {
    struct Test_case {
        std::string s;
        double expected;
    } test_cases[] = {
        {"12.4", 12.4},
        {"  1.34e-3  ", 1.34e-3},
        {"\t-1.23456e+2\n", -1.23456e+2}
    };
    for (const auto& t : test_cases)
        EXPECT_DOUBLE_EQ(str_to_double(t.s), t.expected);
}

TEST(StrToDoubleTest, Invalid) {
    std::string test_cases[] = {"twelve point three", "$2.5", ""};
    for (const std::string& s : test_cases)
        EXPECT_THROW(str_to_double(s), std::runtime_error);
}
