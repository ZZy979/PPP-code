#include <gtest/gtest.h>
#include <cmath>
#include <sstream>
#include <vector>

#include "inner_product.h"
#include "number.h"

TEST(NumberTest, Int) {
    Int a = 1234, b = 4321;
    EXPECT_EQ(a + b, 5555);
    EXPECT_EQ(a - b, -3087);
    EXPECT_EQ(a * b, 5332114);
    EXPECT_EQ(b / a, 3);
    EXPECT_EQ(b % a, 619);

    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "1234");
    ss >> b;
    EXPECT_EQ(b, 1234);
}

TEST(NumberTest, Double) {
    Number<double> c = 2.84, d = 9.65;
    EXPECT_DOUBLE_EQ(c + d, 12.49);
    EXPECT_DOUBLE_EQ(c - d, -6.81);
    EXPECT_DOUBLE_EQ(c * d, 27.406);
    EXPECT_NEAR(d / c, 3.397887, 1e-6);
    // EXPECT_DOUBLE_EQ(d % c, 1.13);
    EXPECT_DOUBLE_EQ(fmod(d, c), 1.13);

    std::stringstream ss;
    ss << c;
    EXPECT_EQ(ss.str(), "2.84");
    ss >> d;
    EXPECT_DOUBLE_EQ(d, 2.84);
}

TEST(NumberTest, InnerProduct) {
    std::vector<Number<double>> price{13.5, 9.9, 5.8, 8.7, 15.8, 6.9, 10};
    std::vector<Number<double>> weight{2, 3.5, 1.6, 0.5, 4, 1.2, 1};
    EXPECT_DOUBLE_EQ(inner_product(price, weight), 156.76);
}
