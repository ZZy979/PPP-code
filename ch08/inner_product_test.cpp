#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>

#include "inner_product.h"

TEST(InnerProduct, SameSize) {
    std::vector<double> price{13.5, 9.9, 5.8, 8.7, 15.8, 6.9, 10};
    std::vector<double> weight{2, 3.5, 1.6, 0.5, 4, 1.2, 1};
    EXPECT_DOUBLE_EQ(inner_product(price, weight), 156.76);
}

TEST(InnerProduct, DifferentSize) {
    std::vector<double> price{10, 20, 30};
    std::vector<double> weight{1, 2};
    EXPECT_THROW(inner_product(price, weight), std::invalid_argument);
}

TEST(InnerProduct, Empty) {
    std::vector<double> price, weight;
    EXPECT_DOUBLE_EQ(inner_product(price, weight), 0);
}
