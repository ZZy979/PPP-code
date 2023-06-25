#include <gtest/gtest.h>
#include <vector>

#include "counted_element.h"
#include "counted_ptr.h"

TEST(CountedPtrTest, CtorAndDtor) {
    counted_ptr<Counted_element> p;
    EXPECT_EQ(Counted_element::count(), 0);

    {
        counted_ptr<Counted_element> q(new Counted_element(888));
        EXPECT_EQ(Counted_element::count(), 1);
    }
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST(CountedPtrTest, CopyConstructor) {
    counted_ptr<Counted_element> p;
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 0);
    counted_ptr<Counted_element> p2 = p;
    EXPECT_EQ(p2.get(), nullptr);
    EXPECT_EQ(p2.use_count(), 0);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 0);

    counted_ptr<Counted_element> q(new Counted_element(888));
    EXPECT_EQ(q.use_count(), 1);
    EXPECT_EQ(Counted_element::count(), 1);
    counted_ptr<Counted_element> q2 = q;
    EXPECT_EQ(q2->x(), 888);
    EXPECT_EQ(q2.use_count(), 2);
    EXPECT_EQ(q->x(), 888);
    EXPECT_EQ(q.use_count(), 2);
    EXPECT_EQ(Counted_element::count(), 1);
}

TEST(CountedPtrTest, CopyAssignment) {
    counted_ptr<Counted_element> p(new Counted_element(123)), p2(new Counted_element(456)), p3(p2), p4;
    EXPECT_EQ(p.use_count(), 1);
    EXPECT_EQ(p2.use_count(), 2);
    EXPECT_EQ(p3.use_count(), 2);
    EXPECT_EQ(Counted_element::count(), 2);

    p2 = p;
    EXPECT_EQ(p2->x(), 123);
    EXPECT_EQ(p.use_count(), 2);
    EXPECT_EQ(p2.use_count(), 2);
    EXPECT_EQ(p3.use_count(), 1);
    EXPECT_EQ(Counted_element::count(), 2);

    p3 = p;
    EXPECT_EQ(p3->x(), 123);
    EXPECT_EQ(p.use_count(), 3);
    EXPECT_EQ(p3.use_count(), 3);
    EXPECT_EQ(Counted_element::count(), 1);

    p3 = p4;
    EXPECT_EQ(p3.get(), nullptr);
    EXPECT_EQ(p.use_count(), 2);
    EXPECT_EQ(p3.use_count(), 0);
    EXPECT_EQ(p4.use_count(), 0);

    p4 = p;
    EXPECT_EQ(p4->x(), 123);
    EXPECT_EQ(p4.use_count(), 3);
    EXPECT_EQ(p3.use_count(), 0);
}

TEST(CountedPtrTest, MoveConstructor) {
    counted_ptr<Counted_element> p;
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 0);
    counted_ptr<Counted_element> p2 = std::move(p);
    EXPECT_EQ(p2.get(), nullptr);
    EXPECT_EQ(p2.use_count(), 0);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 0);

    counted_ptr<Counted_element> q(new Counted_element(888));
    EXPECT_EQ(q.use_count(), 1);
    EXPECT_EQ(Counted_element::count(), 1);
    counted_ptr<Counted_element> q2 = std::move(q);
    EXPECT_EQ(q2->x(), 888);
    EXPECT_EQ(q2.use_count(), 1);
    EXPECT_EQ(q.get(), nullptr);
    EXPECT_EQ(q.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 1);
}

TEST(CountedPtrTest, MoveAssignment) {
    counted_ptr<Counted_element> p(new Counted_element(123)), p2(new Counted_element(456)), p3(p2), p4;
    EXPECT_EQ(p.use_count(), 1);
    EXPECT_EQ(p2.use_count(), 2);
    EXPECT_EQ(p3.use_count(), 2);
    EXPECT_EQ(Counted_element::count(), 2);

    p2 = std::move(p);
    EXPECT_EQ(p2->x(), 123);
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_EQ(p2.use_count(), 1);
    EXPECT_EQ(p3.use_count(), 1);
    EXPECT_EQ(Counted_element::count(), 2);

    p3 = std::move(p2);
    EXPECT_EQ(p3->x(), 123);
    EXPECT_EQ(p3.use_count(), 1);
    EXPECT_EQ(p2.get(), nullptr);
    EXPECT_EQ(p2.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 1);

    p3 = std::move(p4);
    EXPECT_EQ(p3.get(), nullptr);
    EXPECT_EQ(p3.use_count(), 0);
    EXPECT_EQ(p4.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 0);

    p4 = std::move(p3);
    EXPECT_EQ(p4.get(), nullptr);
    EXPECT_EQ(p4.use_count(), 0);
    EXPECT_EQ(p3.use_count(), 0);
}

TEST(CountedPtrTest, Get) {
    counted_ptr<Counted_element> p;
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_FALSE(p);

    counted_ptr<Counted_element> q(new Counted_element(888));
    EXPECT_EQ(q.get()->x(), 888);
    EXPECT_EQ((*q).x(), 888);
    EXPECT_EQ(q->x(), 888);
    EXPECT_EQ(q.use_count(), 1);
    EXPECT_TRUE(q);
}

TEST(CountedPtrTest, UseCount) {
    counted_ptr<int> p(new int(888));
    std::vector<counted_ptr<int>> v;
    EXPECT_EQ(p.use_count(), 1);

    v.resize(5, p);
    EXPECT_EQ(p.use_count(), 6);

    v.resize(2);
    EXPECT_EQ(p.use_count(), 3);
}

TEST(CountedPtrTest, Reset) {
    counted_ptr<Counted_element> p(new Counted_element(123)), p2(p);
    auto q = new Counted_element(456);
    EXPECT_EQ(p.use_count(), 2);
    EXPECT_EQ(Counted_element::count(), 2);

    p.reset(q);
    EXPECT_EQ(p->x(), 456);
    EXPECT_EQ(p.use_count(), 1);
    EXPECT_EQ(Counted_element::count(), 2);

    p.reset();
    EXPECT_EQ(p.get(), nullptr);
    EXPECT_EQ(p.use_count(), 0);
    EXPECT_EQ(Counted_element::count(), 1);
}

TEST(CountedPtrTest, Swap) {
    counted_ptr<Counted_element> p(new Counted_element(123)), p2(new Counted_element(456)), p3(p2);
    EXPECT_EQ(p.use_count(), 1);
    EXPECT_EQ(p2.use_count(), 2);
    EXPECT_EQ(p3.use_count(), 2);
    EXPECT_EQ(Counted_element::count(), 2);

    p.swap(p2);
    EXPECT_EQ(p->x(), 456);
    EXPECT_EQ(p.use_count(), 2);
    EXPECT_EQ(p2->x(), 123);
    EXPECT_EQ(p2.use_count(), 1);
    EXPECT_EQ(p3.use_count(), 2);
    EXPECT_EQ(Counted_element::count(), 2);
}
