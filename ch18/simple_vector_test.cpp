#include <gtest/gtest.h>
#include <utility>

#include "simple_vector.h"

class SimpleVectorV2Test : public ::testing::Test {
protected:
    SimpleVectorV2Test() :v_(5) {
        for (int i = 0; i < v_.size(); ++i)
            v_[i] = 1.1 * i;
    }

    vector v_;
};

TEST_F(SimpleVectorV2Test, Constructor) {
    vector v(3);
    EXPECT_EQ(v.size(), 3);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_DOUBLE_EQ(v[i], 0);
}

TEST_F(SimpleVectorV2Test, InitializerListConstructor) {
    vector v2 = {1, 2, 3};
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], i + 1);
}

TEST_F(SimpleVectorV2Test, CopyConstructor) {
    vector v2 = v_;
    EXPECT_EQ(v2.size(), v_.size());
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], v_[i]);
    v_[1] = 99;
    v2[0] = 88;
    EXPECT_DOUBLE_EQ(v_[0], 0);
    EXPECT_DOUBLE_EQ(v2[1], 1.1);
}

TEST_F(SimpleVectorV2Test, MoveConstructor) {
    int size = v_.size();
    vector v2 = std::move(v_);
    EXPECT_EQ(v2.size(), size);
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], 1.1 * i);
    EXPECT_EQ(v_.size(), 0);
}

TEST_F(SimpleVectorV2Test, CopyAssignment) {
    vector v2 = {1, 2, 3};
    v2 = v_;
    EXPECT_EQ(v2.size(), v_.size());
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], v_[i]);
    v_[1] = 99;
    v2[0] = 88;
    EXPECT_DOUBLE_EQ(v_[0], 0);
    EXPECT_DOUBLE_EQ(v2[1], 1.1);
}

TEST_F(SimpleVectorV2Test, MoveAssignment) {
    vector v2 = {1, 2, 3};
    int size = v_.size();
    v2 = std::move(v_);
    EXPECT_EQ(v2.size(), size);
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], 1.1 * i);
    EXPECT_EQ(v_.size(), 0);
}

TEST_F(SimpleVectorV2Test, Size) {
    EXPECT_EQ(v_.size(), 5);
}

TEST_F(SimpleVectorV2Test, ElementAccess) {
    EXPECT_DOUBLE_EQ(v_[3], 3.3);
    v_[3] = 333.3;
    EXPECT_DOUBLE_EQ(v_[3], 333.3);
}
