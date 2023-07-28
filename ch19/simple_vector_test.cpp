#include <algorithm>
#include <gtest/gtest.h>
#include <utility>

#include "counted_element.h"
#include "simple_vector.h"

// for testing vector of class without default
struct No_default {
    No_default(int) {}
};

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
    vector<double> vd(3);
    EXPECT_EQ(vd.size(), 3);
    EXPECT_EQ(vd.capacity(), 3);
    for (int i = 0; i < vd.size(); ++i)
        EXPECT_DOUBLE_EQ(vd[i], 0);

    vector<int> vi(5, 8);
    EXPECT_EQ(vi.size(), 5);
    EXPECT_EQ(vi.capacity(), 5);
    for (int i = 0; i < vi.size(); ++i)
        EXPECT_EQ(vi[i], 8);

    // class without default
    vector<No_default> vn(10, No_default(8));
    EXPECT_EQ(vn.size(), 10);

    // class with resources
    vector<Counted_element> ve(10);
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(SimpleVectorV3Test, InitializerListConstructor) {
    vector<double> v = {1, 2, 3};
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 3);
    for (int i = 0; i < v.size(); ++i)
        EXPECT_DOUBLE_EQ(v[i], i + 1);

    // class with resources
    vector<Counted_element> ve = {Counted_element(), Counted_element(), Counted_element()};
    EXPECT_EQ(Counted_element::count(), 3);
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

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    vector<Counted_element> ve2 = ve;
    EXPECT_EQ(Counted_element::count(), 10);
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

    // class with resources
    vector<Counted_element> ve(5), ve2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    ve2 = ve;
    EXPECT_EQ(Counted_element::count(), 10);
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

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    vector<Counted_element> ve2 = std::move(ve);
    EXPECT_EQ(Counted_element::count(), 5);
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

    // class with resources
    vector<Counted_element> ve(5), ve2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    ve2 = std::move(ve);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST_F(SimpleVectorV3Test, Destructor) {
    // class with resources
    auto pve = new vector<Counted_element>(8);
    EXPECT_EQ(Counted_element::count(), 8);
    delete pve;
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST_F(SimpleVectorV3Test, ElementAccess) {
    EXPECT_DOUBLE_EQ(v_[3], 3.3);
    EXPECT_DOUBLE_EQ(v_.at(3), 3.3);
    EXPECT_DOUBLE_EQ(v_.front(), 0.0);
    EXPECT_DOUBLE_EQ(v_.back(), 4.4);

    v_[3] = 333.3;
    EXPECT_DOUBLE_EQ(v_[3], 333.3);
    EXPECT_DOUBLE_EQ(v_.at(3), 333.3);

    EXPECT_THROW(v_.at(999), std::out_of_range);
    EXPECT_NO_THROW(v_[999]);
}

TEST_F(SimpleVectorV3Test, Iterator) {
    auto it = std::find(v_.begin(), v_.end(), 3.3);
    EXPECT_NE(it, v_.end());
    EXPECT_DOUBLE_EQ(*it, 3.3);
    EXPECT_EQ(std::find(v_.begin(), v_.end(), 9.9), v_.end());

    double a[5];
    std::copy(v_.begin(), v_.end(), a);
    EXPECT_TRUE(std::equal(v_.begin(), v_.end(), a));
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

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    ve.reserve(8);
    EXPECT_EQ(Counted_element::count(), 5);
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

    v1.resize(15, 123.45);
    for (int i = 10; i < v1.size(); ++i)
        EXPECT_DOUBLE_EQ(v1[i], 123.45);

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

    // class without default
    vector<No_default> vn;
    vn.resize(10, No_default(8));
    EXPECT_EQ(vn.capacity(), 10);
    EXPECT_EQ(vn.size(), 10);

    // class with resources
    vector<Counted_element> ve;
    EXPECT_EQ(Counted_element::count(), 0);
    ve.resize(8);
    EXPECT_EQ(Counted_element::count(), 8);
    ve.resize(3);
    EXPECT_EQ(Counted_element::count(), 3);
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

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    ve.push_back(Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(SimpleVectorV3Test, PopBack) {
    v_.pop_back();
    EXPECT_EQ(v_.size(), 4);
    EXPECT_EQ(v_.capacity(), 5);

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    ve.pop_back();
    EXPECT_EQ(Counted_element::count(), 4);
}

TEST_F(SimpleVectorV3Test, Insert) {
    // empty vector
    vector<double> v0;
    auto p = v0.insert(v0.end(), 42);
    EXPECT_EQ(p, v0.begin());
    EXPECT_DOUBLE_EQ(*p, 42);
    EXPECT_EQ(v0.size(), 1);
    EXPECT_EQ(v0.capacity(), 8);

    // reallocation
    p = v_.insert(v_.begin() + 4, 42);
    EXPECT_EQ(p, v_.begin() + 4);
    EXPECT_DOUBLE_EQ(*p, 42);
    EXPECT_EQ(v_.size(), 6);
    EXPECT_EQ(v_.capacity(), 10);

    // insert at end()
    p = v_.insert(v_.end(), 5.5);
    EXPECT_EQ(p, v_.begin() + 6);
    EXPECT_DOUBLE_EQ(*p, 5.5);
    EXPECT_EQ(v_.size(), 7);

    // insert at begin()
    p = v_.insert(v_.begin(), -1.1);
    EXPECT_EQ(p, v_.begin());
    EXPECT_DOUBLE_EQ(*p, -1.1);
    EXPECT_EQ(v_.size(), 8);

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    ve.insert(ve.begin() + 2, Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(SimpleVectorV3Test, Erase) {
    // empty vector
    vector<double> v0;
    EXPECT_EQ(v0.erase(v0.end()), v0.end());

    // erase end()
    EXPECT_EQ(v_.erase(v_.end()), v_.end());
    EXPECT_EQ(v_.size(), 5);

    // erase last element
    auto p = v_.erase(v_.begin() + 4);
    EXPECT_EQ(p, v_.end());
    EXPECT_EQ(v_.size(), 4);

    // erase first element
    p = v_.erase(v_.begin());
    EXPECT_EQ(p, v_.begin());
    EXPECT_DOUBLE_EQ(*p, 1.1);
    EXPECT_EQ(v_.size(), 3);

    // erase middle element
    p = v_.erase(v_.begin() + 1);
    EXPECT_EQ(p, v_.begin() + 1);
    EXPECT_DOUBLE_EQ(*p, 3.3);
    EXPECT_EQ(v_.size(), 2);

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    ve.erase(ve.begin() + 2);
    EXPECT_EQ(Counted_element::count(), 4);
}

TEST_F(SimpleVectorV3Test, Clear) {
    // empty vector
    vector<double> v0;
    v0.clear();
    EXPECT_EQ(v0.size(), 0);

    // non-empty vector
    v_.clear();
    EXPECT_EQ(v_.size(), 0);
    EXPECT_EQ(v_.capacity(), 5);

    // class with resources
    vector<Counted_element> ve(5);
    EXPECT_EQ(Counted_element::count(), 5);
    ve.clear();
    EXPECT_EQ(Counted_element::count(), 0);
}
