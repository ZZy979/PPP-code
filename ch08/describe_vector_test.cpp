#include <gtest/gtest.h>
#include <vector>

#include "describe_vector.h"

TEST(Maxv, Nonempty) {
    std::vector<double> v{
        70.3, -34.21, 36.52, -14.13, 16.97, -85.57, 7.23, -8.87, 95.09, -40.96,
        -9.93, 81.09, -9.53, -13.59, 27.68, -95.84, 17.83, 17.25, 70.05, 84.91
    };
    EXPECT_DOUBLE_EQ(maxv(v), 95.09);
}

TEST(Maxv, Empty) {
    std::vector<double> v;
    EXPECT_THROW(maxv(v), std::invalid_argument);
}

TEST(DescribeDouble, OddSize) {
    std::vector<double> v{
        90.03, 29.22, 93.31, 43.39, 37.22, 58.3, 22.89, 60.97, 41.13, 17.27, 23.14, 8.41,
        15.34, 6.33, 66.45, 36.19, 56.28, 22.67, 46.35, 53.12, 25.3, 29.87, -9.79, 19.62,
        17.88, -6.84, 94.02, 9.61, -6.17, 58.52, 59.27, 9.44, 86.94, 74.9, 84.11
    };
    Double_result result = describe(v);
    EXPECT_DOUBLE_EQ(result.min, -9.79);
    EXPECT_DOUBLE_EQ(result.max, 94.02);
    EXPECT_NEAR(result.mean, 39.276857, 1e-6);
    EXPECT_DOUBLE_EQ(result.median, 36.19);
}

TEST(DescribeDouble, EvenSize) {
    std::vector<double> v{
        2.39, -1.15, -19.15, 7.58, -96.84, 0.33, -33.95, 2.25, -24.48, -14.46,
        -72.92, -65.42, -82.62, -88.7, -41.57, -70.32, -28.22, -30.6, -92.99, 9.03,
        -93.15, -8.79, -49.59, -97.64, -11.74, -93.32, 9.38, 4.24, -78.28, -95.39
    };
    Double_result result = describe(v);
    EXPECT_DOUBLE_EQ(result.min, -97.64);
    EXPECT_DOUBLE_EQ(result.max, 9.38);
    EXPECT_NEAR(result.mean, -41.869667, 1e-6);
    EXPECT_DOUBLE_EQ(result.median, -32.275);
}

TEST(DescribeDouble, Empty) {
    std::vector<double> v;
    EXPECT_THROW(describe(v), std::invalid_argument);
}

TEST(DescribeString, Nonempty) {
    std::vector<std::string> v{
        "bool", "char", "short", "int", "long", "float", "double",
        "if", "switch", "for", "while", "do"
    };
    std::vector<int> expected_length{4, 4, 5, 3, 4, 5, 6, 2, 6, 3, 5, 2};
    String_result result;
    std::vector<int> actual_length = describe(v, result);
    EXPECT_EQ(actual_length, expected_length);
    EXPECT_EQ(result.shortest, "if");
    EXPECT_EQ(result.longest, "double");
    EXPECT_EQ(result.min, "bool");
    EXPECT_EQ(result.max, "while");
}

TEST(DescribeString, Empty) {
    std::vector<std::string> v;
    String_result result;
    EXPECT_THROW(describe(v, result), std::invalid_argument);
}
