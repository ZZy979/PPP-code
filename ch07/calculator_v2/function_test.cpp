#include <gtest/gtest.h>

#include <cmath>
#include <vector>

#include "function.h"

TEST(CalculatorV2FunctionTest, IsOneArgumentFunction) {
    std::vector<std::pair<std::string, bool>> test_cases = {
        {"sin", true}, {"sqrt", true}, {"pow", false}, {"abc", false}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(is_one_argument_function(t.first), t.second);
}

TEST(CalculatorV2FunctionTest, IsTwoArgumentFunction) {
    std::vector<std::pair<std::string, bool>> test_cases = {
        {"sin", false}, {"sqrt", false}, {"pow", true}, {"abc", false}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(is_two_argument_function(t.first), t.second);
}

TEST(CalculatorV2FunctionTest, IsFunctionName) {
    std::vector<std::pair<std::string, bool>> test_cases = {
        {"sin", true}, {"sqrt", true}, {"pow", true},
        {"asin", false}, {"abc", false}, {"123", false}, {"", false}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(is_function_name(t.first), t.second);
}

TEST(CalculatorV2FunctionTest, CalculateFunction) {
    struct Test_case {
        std::string name;
        double x;
        double y;
        double expected;
    };
    const double pi = 4 * atan(1);
    std::vector<Test_case> test_cases = {
        {"sin", pi / 6, 0, 0.5},
        {"cos", pi, 0, -1},
        {"tan", pi / 3, 0, sqrt(3)},
        {"exp", 2.5, 0, exp(2.5)},
        {"log", 4.3e6, 0, log(4.3e6)},
        {"sqrt", 25, 0, 5},
        {"fabs", -8, 0, 8},
        {"pow", 2, 3, 8},
        {"pow", 5, 0.5, sqrt(5)},
        {"pow", 4, -1, 0.25},
        {"pow", -4, -2, 0.0625},
        {"pow", pi, 0, 1}
    };
    for (const auto& t : test_cases)
        EXPECT_NEAR(calculate_function(t.name, t.x, t.y), t.expected, 1e-6);
}

TEST(CalculatorV2FunctionTest, CalculateFunctionBadArgument) {
    EXPECT_TRUE(std::isnan(calculate_function("sqrt", -1)));
    EXPECT_TRUE(std::isinf(calculate_function("log", 0)));
    EXPECT_TRUE(std::isnan(calculate_function("pow", -4, -0.5)));
}

TEST(CalculatorV2FunctionTest, CalculateFunctionInvalidName) {
    EXPECT_THROW(calculate_function("asin", 0.5), std::invalid_argument);
}
