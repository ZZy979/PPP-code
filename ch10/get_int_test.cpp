#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "get_int.h"

TEST(GetInt, Success) {
    std::vector<std::pair<std::string, int>> test_cases{
        {"6", 6},
        {" 15 0 8 4", 8},
        {"3.1415926", 3},
        {"***%%%&&&1", 1},
        {"12(x-2y)/(z+5)", 5},
        {"-4abc @#$.9!", 9}
    };
    for (const auto& t : test_cases) {
        std::istringstream iss(t.first);
        EXPECT_EQ(get_int(iss, 1, 10), t.second);
    }
}

TEST(GetInt, Failed) {
    std::vector<std::string> test_cases{
        "", "15 0 -6", "-3.1415926", "abc", "***%%%&&&111", "12(x-2y)/(z+55)"
    };
    for (const auto& t : test_cases) {
        std::istringstream iss(t);
        EXPECT_THROW(get_int(iss, 1, 10), std::runtime_error);
    }
}
