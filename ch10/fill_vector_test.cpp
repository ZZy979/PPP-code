#include <gtest/gtest.h>

#include <sstream>
#include <vector>

#include "fill_vector.h"

TEST(FillVectorTest, Eof) {
    std::istringstream iss("1 2 3 4 5");
    std::vector<int> v, expected{1, 2, 3, 4, 5};
    fill_vector(iss, v, '*');
    EXPECT_EQ(v, expected);
    EXPECT_TRUE(iss.eof());
}

TEST(FillVectorTest, Terminator) {
    std::istringstream iss("1 2 3 4 5*6 7");
    std::vector<int> v, expected{1, 2, 3, 4, 5};
    fill_vector(iss, v, '*');
    EXPECT_EQ(v, expected);
    EXPECT_TRUE(iss.good());
    EXPECT_EQ(iss.get(), '6');
}

TEST(FillVectorTest, Bad) {
    std::istringstream iss("1 2 3 4 5");
    std::vector<int> v;
    iss.setstate(std::ios_base::badbit);
    EXPECT_THROW(fill_vector(iss, v, '*'), std::ios_base::failure);
    EXPECT_TRUE(iss.bad());
}

TEST(FillVectorTest, NotTerminator) {
    std::istringstream iss("1 2 3 4 5@6 7");
    std::vector<int> v, expected{1, 2, 3, 4, 5};
    fill_vector(iss, v, '*');
    EXPECT_EQ(v, expected);
    EXPECT_TRUE(iss.fail());
    iss.clear();
    EXPECT_EQ(iss.get(), '@');
}
