#include <gtest/gtest.h>

#include "simple_vector.h"

class SimpleVectorV1Test : public ::testing::Test {
protected:
    SimpleVectorV1Test() :v_(5) {
        for (int i = 0; i < v_.size(); ++i)
            v_.set(i, 1.1 * i);
    }

    vector v_;
};

TEST_F(SimpleVectorV1Test, Constructor) {
    vector v(3);
    EXPECT_EQ(v.size(), 3);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_DOUBLE_EQ(v.get(i), 0);
}

TEST_F(SimpleVectorV1Test, Size) {
    EXPECT_EQ(v_.size(), 5);
}

TEST_F(SimpleVectorV1Test, ElementAccess) {
    EXPECT_DOUBLE_EQ(v_.get(3), 3.3);
    v_.set(3, 333.3);
    EXPECT_DOUBLE_EQ(v_.get(3), 333.3);
}
