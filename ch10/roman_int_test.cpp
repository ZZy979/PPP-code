#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "roman_int.h"

TEST(RomanIntTest, RomanToInt) {
    std::vector<std::pair<std::string, int>> test_cases{
        {"", 0}, {"II", 2}, {"IV", 4}, {"IX", 9},
        {"XXI", 21}, {"CIV", 104}, {"CXXV", 125}, {"DCLVIII", 658}, {"CMLXXIX", 979},
        {"MCCXLVIII", 1248}, {"MCMXCVII", 1997}, {"MMMCDIX", 3409}, {"MMMMMMDCLXVI", 6666},
        {"IIII", 4}, {"VIIII", 9}, {"cXxV", 125}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(Roman_int(t.first).as_int(), t.second);
}

TEST(RomanIntTest, RomanToIntInvalid) {
    std::vector<std::string> test_cases{"AI", "D2", "VII?"};
    for (const std::string& s : test_cases)
        EXPECT_THROW(Roman_int{s}, std::out_of_range);
}

TEST(RomanIntTest, IntToRoman) {
    std::vector<std::pair<int, std::string>> test_cases{
        {0, ""}, {2, "II"}, {4, "IV"}, {9, "IX"},
        {21, "XXI"}, {104, "CIV"}, {125, "CXXV"}, {658, "DCLVIII"}, {979, "CMLXXIX"},
        {1248, "MCCXLVIII"}, {1997, "MCMXCVII"}, {3409, "MMMCDIX"}, {6666, "MMMMMMDCLXVI"}
    };
    for (const auto& t : test_cases)
        EXPECT_EQ(Roman_int(t.first).to_string(), t.second);
}

TEST(RomanIntTest, InputOutput) {
    std::istringstream iss("MMDCCLXVIII");
    Roman_int r;
    EXPECT_TRUE(iss >> r);
    EXPECT_EQ(r.as_int(), 2768);

    std::ostringstream oss;
    oss << "Roman " << r << " equals " << r.as_int() << '\n';
    EXPECT_EQ(oss.str(), "Roman MMDCCLXVIII equals 2768\n");
}
