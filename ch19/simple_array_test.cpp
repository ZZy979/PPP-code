#include <algorithm>
#include <gtest/gtest.h>

#include "simple_array.h"

class SimpleArrayTest : public ::testing::Test {
protected:
    array<double, 5> a_ = {0.0, 1.1, 2.2, 3.3, 4.4};
};

TEST_F(SimpleArrayTest, DefaultConstructor) {
    array<int, 3> a;
    EXPECT_EQ(a.size(), 3);
}

TEST_F(SimpleArrayTest, InitializerListConstructor) {
    EXPECT_EQ(a_.size(), 5);
    for (int i = 0; i < a_.size(); ++i)
        EXPECT_DOUBLE_EQ(a_[i], 1.1 * i);
}

TEST_F(SimpleArrayTest, CopyConstructor) {
    array<double, 5> a2 = a_;
    EXPECT_EQ(a2.size(), a_.size());
    for (int i = 0; i < a2.size(); ++i)
        EXPECT_DOUBLE_EQ(a2[i], a_[i]);
    a_[1] = 99;
    a2[0] = 88;
    EXPECT_DOUBLE_EQ(a_[0], 0);
    EXPECT_DOUBLE_EQ(a2[1], 1.1);
}

TEST_F(SimpleArrayTest, CopyAssignment) {
    // self-assignment
    a_ = a_;
    EXPECT_EQ(a_.size(), 5);
    for (int i = 0; i < a_.size(); ++i)
        EXPECT_DOUBLE_EQ(a_[i], 1.1 * i);

    array<double, 5> a2 = {1, 2, 3, 4, 5};
    a2 = a_;
    EXPECT_EQ(a2.size(), a_.size());
    for (int i = 0; i < a2.size(); ++i)
        EXPECT_DOUBLE_EQ(a2[i], a_[i]);
    a_[1] = 99;
    a2[0] = 88;
    EXPECT_DOUBLE_EQ(a_[0], 0);
    EXPECT_DOUBLE_EQ(a2[1], 1.1);
}

TEST_F(SimpleArrayTest, ElementAccess) {
    EXPECT_DOUBLE_EQ(a_[3], 3.3);
    EXPECT_DOUBLE_EQ(a_.at(3), 3.3);

    a_[3] = 333.3;
    EXPECT_DOUBLE_EQ(a_[3], 333.3);
    EXPECT_DOUBLE_EQ(a_.at(3), 333.3);

    EXPECT_THROW(a_.at(999), std::out_of_range);
    EXPECT_NO_THROW(a_[999]);

    double* p = a_.data();
    EXPECT_EQ(p + 2, &a_[2]);
    EXPECT_DOUBLE_EQ(p[2], 2.2);
    p[2] = 222.2;
    EXPECT_DOUBLE_EQ(p[2], 222.2);
}

TEST_F(SimpleArrayTest, Size) {
    EXPECT_EQ(a_.size(), 5);
}

TEST_F(SimpleArrayTest, Iterator) {
    auto it = std::find(a_.begin(), a_.end(), 3.3);
    EXPECT_NE(it, a_.end());
    EXPECT_DOUBLE_EQ(*it, 3.3);
    EXPECT_EQ(std::find(a_.begin(), a_.end(), 9.9), a_.end());

    double a[5];
    std::copy(a_.begin(), a_.end(), a);
    EXPECT_TRUE(std::equal(a_.begin(), a_.end(), a));
}
