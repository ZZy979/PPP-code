#include <gtest/gtest.h>

#include "counted_element.h"
#include "simple_allocator.h"
#include "simple_vector.h"

using Vector = vector<Counted_element, Simple_allocator<Counted_element>>;

TEST(SimpleAllocatorTest, VectorConstructor) {
    Vector v(10);
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST(SimpleAllocatorTest, VectorCopyConstructor) {
    Vector v(5);
    EXPECT_EQ(Counted_element::count(), 5);
    Vector v2 = v;
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST(SimpleAllocatorTest, VectorCopyAssignment) {
    Vector v(5), v2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    v2 = v;
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST(SimpleAllocatorTest, VectorMoveConstructor) {
    Vector v(5);
    EXPECT_EQ(Counted_element::count(), 5);
    Vector v2 = std::move(v);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST(SimpleAllocatorTest, VectorMoveAssignment) {
    Vector v(5), v2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    v2 = std::move(v);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST(SimpleAllocatorTest, VectorDestructor) {
    auto pv = new Vector (8);
    EXPECT_EQ(Counted_element::count(), 8);
    delete pv;
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST(SimpleAllocatorTest, VectorResize) {
    Vector v;
    EXPECT_EQ(Counted_element::count(), 0);
    v.resize(8);
    EXPECT_EQ(Counted_element::count(), 8);
    v.resize(3);
    EXPECT_EQ(Counted_element::count(), 3);
}
