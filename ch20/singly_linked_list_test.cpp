#include <algorithm>
#include <gtest/gtest.h>

#include "ch19/counted_element.h"
#include "singly_linked_list.h"

class SinglyLinkedListTest : public ::testing::Test {
protected:
    slist<double> l_ = {0.0, 1.1, 2.2, 3.3, 4.4};
};

// for testing list of class without default
struct No_default {
    No_default(int) {}
};

template<class T>
size_t size(const slist<T>& l) {
    return std::distance(l.begin(), l.end());
}

TEST_F(SinglyLinkedListTest, DefaultConstructor) {
    slist<double> l;
    EXPECT_TRUE(l.empty());
    EXPECT_EQ(l.begin(), l.end());
}

TEST_F(SinglyLinkedListTest, Constructor) {
    slist<double> ld(3);
    EXPECT_EQ(size(ld), 3);
    for (double d : ld)
        EXPECT_DOUBLE_EQ(d, 0);

    slist<int> li(5, 8);
    EXPECT_EQ(size(li), 5);
    for (int i : li)
        EXPECT_EQ(i, 8);

    // class without default
    slist<No_default> ln(10, No_default(8));
    EXPECT_EQ(size(ln), 10);

    // class with resources
    slist<Counted_element> le(10);
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(SinglyLinkedListTest, InitializerListConstructor) {
    slist<double> ld = {1, 2, 3};
    double expected[] = {1, 2, 3};
    EXPECT_EQ(size(ld), 3);
    EXPECT_TRUE(std::equal(ld.begin(), ld.end(), expected));

    // class with resources
    slist<Counted_element> le = {Counted_element(), Counted_element(), Counted_element()};
    EXPECT_EQ(Counted_element::count(), 3);
}

TEST_F(SinglyLinkedListTest, CopyConstructor) {
    slist<double> l2 = l_;
    EXPECT_EQ(size(l2), size(l_));
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), l_.begin()));
    *std::next(l_.begin()) = 99;
    l2.front() = 88;
    EXPECT_DOUBLE_EQ(l_.front(), 0);
    EXPECT_DOUBLE_EQ(*std::next(l2.begin()), 1.1);

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    slist<Counted_element> le2 = le;
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(SinglyLinkedListTest, CopyAssignment) {
    // self-assignment
    l_ = l_;
    double expected[] = {0.0, 1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(size(l_), 5);
    EXPECT_TRUE(std::equal(l_.begin(), l_.end(), expected));

    slist<double> l2 = {1, 2, 3};
    l2 = l_;
    EXPECT_EQ(size(l2), size(l_));
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), l_.begin()));
    *std::next(l_.begin()) = 99;
    l2.front() = 88;
    EXPECT_DOUBLE_EQ(l_.front(), 0);
    EXPECT_DOUBLE_EQ(*std::next(l2.begin()), 1.1);

    // class with resources
    slist<Counted_element> le(5), le2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    le2 = le;
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(SinglyLinkedListTest, MoveConstructor) {
    int sz = size(l_);
    slist<double> l2 = std::move(l_);
    double expected[] = {0.0, 1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(size(l2), sz);
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), expected));
    EXPECT_TRUE(l_.empty());

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    slist<Counted_element> le2 = std::move(le);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST_F(SinglyLinkedListTest, MoveAssignment) {
    slist<double> l2 = {1, 2, 3};
    int sz = size(l_);
    l2 = std::move(l_);
    double expected[] = {0.0, 1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(size(l2), sz);
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), expected));
    EXPECT_TRUE(l_.empty());

    // class with resources
    slist<Counted_element> le(5), le2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    le2 = std::move(le);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST_F(SinglyLinkedListTest, Destructor) {
    // class with resources
    auto ple = new slist<Counted_element>(8);
    EXPECT_EQ(Counted_element::count(), 8);
    delete ple;
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST_F(SinglyLinkedListTest, Iterator) {
    auto it = std::find(l_.begin(), l_.end(), 3.3);
    EXPECT_NE(it, l_.end());
    EXPECT_DOUBLE_EQ(*it, 3.3);
    EXPECT_EQ(std::find(l_.begin(), l_.end(), 9.9), l_.end());

    double a[5];
    std::copy(l_.begin(), l_.end(), a);
    EXPECT_TRUE(std::equal(l_.begin(), l_.end(), a));
}

TEST_F(SinglyLinkedListTest, Insert) {
    // empty list
    slist<double> l0;
    auto p = l0.insert_after(l0.before_begin(), 42);
    EXPECT_EQ(p, l0.begin());
    EXPECT_DOUBLE_EQ(*p, 42);
    EXPECT_EQ(size(l0), 1);

    // insert at middle
    p = l_.insert_after(std::next(l_.begin(), 3), 42);
    EXPECT_EQ(std::distance(l_.begin(), p), 4);
    EXPECT_DOUBLE_EQ(*p, 42);
    EXPECT_EQ(size(l_), 6);

    // can't insert at end()

    // insert at begin()
    p = l_.insert_after(l_.before_begin(), -1.1);
    EXPECT_EQ(p, l_.begin());
    EXPECT_DOUBLE_EQ(*p, -1.1);
    EXPECT_EQ(size(l_), 7);

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.insert_after(std::next(le.begin(), 2), Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(SinglyLinkedListTest, Erase) {
    // erase last element
    auto p = l_.erase_after(std::next(l_.begin(), 3));
    EXPECT_EQ(p, l_.end());
    EXPECT_EQ(size(l_), 4);

    // erase first element
    p = l_.erase_after(l_.before_begin());
    EXPECT_EQ(p, l_.begin());
    EXPECT_DOUBLE_EQ(*p, 1.1);
    EXPECT_EQ(size(l_), 3);

    // erase middle element
    p = l_.erase_after(l_.begin());
    EXPECT_EQ(p, std::next(l_.begin()));
    EXPECT_DOUBLE_EQ(*p, 3.3);
    EXPECT_EQ(size(l_), 2);

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.erase_after(std::next(le.begin(), 2));
    EXPECT_EQ(Counted_element::count(), 4);
}

TEST_F(SinglyLinkedListTest, Clear) {
    // empty list
    slist<double> l0;
    l0.clear();
    EXPECT_TRUE(l0.empty());

    // non-empty list
    l_.clear();
    EXPECT_TRUE(l_.empty());

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.clear();
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST_F(SinglyLinkedListTest, PushFront) {
    // empty list
    slist<double> l0;
    l0.push_front(42);
    EXPECT_EQ(size(l0), 1);
    EXPECT_DOUBLE_EQ(l0.front(), 42);

    // non-empty list
    l_.push_front(5.5);
    EXPECT_EQ(size(l_), 6);
    EXPECT_DOUBLE_EQ(l_.front(), 5.5);

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.push_front(Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(SinglyLinkedListTest, PopFront) {
    l_.pop_front();
    EXPECT_EQ(size(l_), 4);

    // class with resources
    slist<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.pop_front();
    EXPECT_EQ(Counted_element::count(), 4);
}
