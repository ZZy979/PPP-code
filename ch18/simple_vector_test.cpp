#include <gtest/gtest.h>

#include "simple_vector.h"

class SimpleVectorV2Test : public ::testing::Test {
protected:
    SimpleVectorV2Test() :v_(5) {
        for (int i = 0; i < v_.size(); ++i)
            v_.set(i, 1.1 * i);
    }

    vector v_;
};

TEST_F(SimpleVectorV2Test, Constructor) {
    // default constructor
    vector v(3);
    EXPECT_EQ(v.size(), 3);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_DOUBLE_EQ(v.get(i), 0);

    // initializer-list constructor
    vector v2 = {1, 2, 3};
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2.get(i), i + 1);

    // copy constructor
    vector v3 = v2;
    EXPECT_EQ(v3.size(), v2.size());
    for (int i = 0; i < v3.size(); ++i)
        EXPECT_DOUBLE_EQ(v3.get(i), v2.get(i));
    v2.set(1, 99);
    v3.set(0, 88);
    EXPECT_DOUBLE_EQ(v2.get(0), 1);
    EXPECT_DOUBLE_EQ(v3.get(1), 2);
}

TEST_F(SimpleVectorV2Test, CopyAssignment) {
    vector v = {1, 2, 3}, v2 = {4, 5, 6, 7};
    v2 = v;
    EXPECT_EQ(v2.size(), v.size());
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2.get(i), v.get(i));
    v.set(1, 99);
    v2.set(0, 88);
    EXPECT_DOUBLE_EQ(v.get(0), 1);
    EXPECT_DOUBLE_EQ(v2.get(1), 2);
}

TEST_F(SimpleVectorV2Test, Size) {
    EXPECT_EQ(v_.size(), 5);
}

TEST_F(SimpleVectorV2Test, ElementAccess) {
    EXPECT_DOUBLE_EQ(v_.get(3), 3.3);
    v_.set(3, 333.3);
    EXPECT_DOUBLE_EQ(v_.get(3), 333.3);
}
