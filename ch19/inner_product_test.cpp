#include <gtest/gtest.h>

#include "inner_product.h"

TEST(InnerProductV2, SameSize) {
    std::vector<double> price{13.5, 9.9, 5.8, 8.7, 15.8, 6.9, 10};
    std::vector<double> weight{2, 3.5, 1.6, 0.5, 4, 1.2, 1};
    std::vector<bool> filter{true, false, true, true, true, false, false};
    EXPECT_DOUBLE_EQ(inner_product(price, weight), 156.76);
    EXPECT_DOUBLE_EQ(inner_product(price, filter, 100.0), 143.8);
}

TEST(InnerProductV2, DifferentSize) {
    std::vector<double> price{10, 20, 30};
    std::vector<double> weight{1, 2};
    EXPECT_THROW(inner_product(price, weight), std::invalid_argument);
}

TEST(InnerProductV2, Empty) {
    std::vector<double> price, weight;
    EXPECT_DOUBLE_EQ(inner_product(price, weight), 0.0);
}
