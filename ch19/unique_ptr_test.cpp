#include <gtest/gtest.h>

#include "counted_element.h"
#include "unique_ptr.h"

TEST(UniquePtrTest, CtorAndDtor) {
    unique_ptr<Counted_element> p;
    EXPECT_EQ(Counted_element::count(), 0);

    {
        unique_ptr<Counted_element> q(new Counted_element(888));
        EXPECT_EQ(Counted_element::count(), 1);
    }
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST(UniquePtrTest, MoveConstructor) {
    unique_ptr<Counted_element> p(new Counted_element(888));
    EXPECT_EQ(Counted_element::count(), 1);

    unique_ptr<Counted_element> q = std::move(p);
    EXPECT_EQ(q->x(), 888);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(Counted_element::count(), 1);
}

TEST(UniquePtrTest, MoveAssignment) {
    unique_ptr<Counted_element> p(new Counted_element(123)), q(new Counted_element(456));
    EXPECT_EQ(Counted_element::count(), 2);

    q = std::move(p);
    EXPECT_EQ(q->x(), 123);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(Counted_element::count(), 1);
}

TEST(UniquePtrTest, Get) {
    unique_ptr<Counted_element> p;
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_FALSE(p);

    unique_ptr<Counted_element> q(new Counted_element(888));
    EXPECT_EQ(q.get()->x(), 888);
    EXPECT_EQ((*q).x(), 888);
    EXPECT_EQ(q->x(), 888);
    EXPECT_TRUE(q);
}

TEST(UniquePtrTest, Release) {
    unique_ptr<Counted_element> p(new Counted_element(888));
    EXPECT_EQ(Counted_element::count(), 1);

    Counted_element* q = p.release();
    EXPECT_EQ(q->x(), 888);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(Counted_element::count(), 1);
    delete q;
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST(UniquePtrTest, Reset) {
    unique_ptr<Counted_element> p(new Counted_element(123));
    auto q = new Counted_element(456);
    EXPECT_EQ(Counted_element::count(), 2);

    p.reset(q);
    EXPECT_EQ(Counted_element::count(), 1);
    EXPECT_EQ(p->x(), 456);

    p.reset();
    EXPECT_EQ(Counted_element::count(), 0);
    EXPECT_EQ(p.get(), nullptr);
}

TEST(UniquePtrTest, Swap) {
    unique_ptr<Counted_element> p(new Counted_element(123)), q(new Counted_element(456));
    EXPECT_EQ(Counted_element::count(), 2);

    p.swap(q);
    EXPECT_EQ(Counted_element::count(), 2);
    EXPECT_EQ(p->x(), 456);
    EXPECT_EQ(q->x(), 123);
}
