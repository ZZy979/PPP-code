#include <gtest/gtest.h>
#include <utility>

#include "simple_vector.h"

class SimpleVectorV3Test : public ::testing::Test {
protected:
    vector<double> v_ = {0.0, 1.1, 2.2, 3.3, 4.4};
};

TEST_F(SimpleVectorV3Test, DefaultConstructor) {
    vector<double> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

TEST_F(SimpleVectorV3Test, Constructor) {
    vector<double> v(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 3);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_DOUBLE_EQ(v[i], 0);
}

TEST_F(SimpleVectorV3Test, InitializerListConstructor) {
    vector<double> v = {1, 2, 3};
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 3);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_DOUBLE_EQ(v[i], i + 1);
}

TEST_F(SimpleVectorV3Test, CopyConstructor) {
    vector<double> v2 = v_;
    EXPECT_EQ(v2.size(), v_.size());
    EXPECT_EQ(v2.capacity(), v_.capacity());
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], v_[i]);
    v_[1] = 99;
    v2[0] = 88;
    EXPECT_DOUBLE_EQ(v_[0], 0);
    EXPECT_DOUBLE_EQ(v2[1], 1.1);
}

TEST_F(SimpleVectorV3Test, CopyAssignment) {
    // self-assignment
    v_ = v_;
    EXPECT_EQ(v_.size(), 5);
    for (int i = 0; i < v_.size(); ++i)
        EXPECT_DOUBLE_EQ(v_[i], 1.1 * i);

    vector<double> v2 = {1, 2, 3};
    v_.reserve(8);
    v2 = v_;
    EXPECT_EQ(v2.size(), v_.size());
    EXPECT_EQ(v2.capacity(), v_.size());
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], v_[i]);
    v_[1] = 99;
    v2[0] = 88;
    EXPECT_DOUBLE_EQ(v_[0], 0);
    EXPECT_DOUBLE_EQ(v2[1], 1.1);
}

TEST_F(SimpleVectorV3Test, MoveConstructor) {
    int size = v_.size(), capacity = v_.capacity();
    vector<double> v2 = std::move(v_);
    EXPECT_EQ(v2.size(), size);
    EXPECT_EQ(v2.capacity(), capacity);
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], 1.1 * i);
    EXPECT_EQ(v_.size(), 0);
    EXPECT_EQ(v_.capacity(), 0);
}

TEST_F(SimpleVectorV3Test, MoveAssignment) {
    vector<double> v2 = {1, 2, 3};
    int size = v_.size(), capacity = v_.capacity();
    v2 = std::move(v_);
    EXPECT_EQ(v2.size(), size);
    EXPECT_EQ(v2.capacity(), capacity);
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], 1.1 * i);
    EXPECT_EQ(v_.size(), 0);
    EXPECT_EQ(v_.capacity(), 0);
}

TEST_F(SimpleVectorV3Test, ElementAccess) {
    EXPECT_DOUBLE_EQ(v_[3], 3.3);
    v_[3] = 333.3;
    EXPECT_DOUBLE_EQ(v_[3], 333.3);
}

TEST_F(SimpleVectorV3Test, SizeAndCapacity) {
    EXPECT_EQ(v_.size(), 5);
    EXPECT_EQ(v_.capacity(), 5);
}

TEST_F(SimpleVectorV3Test, Reserve) {
    // new_space < capacity()
    v_.reserve(3);
    EXPECT_EQ(v_.capacity(), 5);

    // new_space == capacity()
    v_.reserve(5);
    EXPECT_EQ(v_.capacity(), 5);

    // new_space > capacity()
    v_.reserve(8);
    EXPECT_EQ(v_.capacity(), 8);
}

TEST_F(SimpleVectorV3Test, Resize) {
    // size() == 5, capacity() == 8
    v_.reserve(8);

    // new_size > capacity()
    vector<double> v1 = v_;
    v1.resize(10);
    EXPECT_EQ(v1.capacity(), 10);
    EXPECT_EQ(v1.size(), 10);
    for (int i = 0; i < v1.size(); ++i)
        EXPECT_DOUBLE_EQ(v1[i], i < 5 ? 1.1 * i : 0.0);

    // size() < new_size <= capacity()
    vector<double> v2 = v_;
    v2.resize(6);
    EXPECT_EQ(v2.capacity(), 8);
    EXPECT_EQ(v2.size(), 6);
    for (int i = 0; i < v2.size(); ++i)
        EXPECT_DOUBLE_EQ(v2[i], i < 5 ? 1.1 * i : 0.0);

    // new_size == size()
    vector<double> v3 = v_;
    v3.resize(5);
    EXPECT_EQ(v3.capacity(), 8);
    EXPECT_EQ(v3.size(), 5);
    for (int i = 0; i < v3.size(); ++i)
        EXPECT_DOUBLE_EQ(v3[i], 1.1 * i);

    // new_size < size()
    vector<double> v4 = v_;
    v4.resize(2);
    EXPECT_EQ(v4.capacity(), 8);
    EXPECT_EQ(v4.size(), 2);
    for (int i = 0; i < v4.size(); ++i)
        EXPECT_DOUBLE_EQ(v4[i], 1.1 * i);
}

TEST_F(SimpleVectorV3Test, PushBack) {
    // empty vector
    vector<double> v0;
    v0.push_back(42);
    EXPECT_EQ(v0.capacity(), 8);
    EXPECT_EQ(v0.size(), 1);
    EXPECT_DOUBLE_EQ(v0[0], 42);

    // reallocation
    v_.push_back(5.5);
    EXPECT_EQ(v_.capacity(), 10);
    EXPECT_EQ(v_.size(), 6);
    EXPECT_DOUBLE_EQ(v_[5], 5.5);

    // no reallocation
    v_.push_back(6.6);
    EXPECT_EQ(v_.capacity(), 10);
    EXPECT_EQ(v_.size(), 7);
    EXPECT_DOUBLE_EQ(v_[6], 6.6);
}
