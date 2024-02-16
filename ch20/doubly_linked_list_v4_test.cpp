#include <algorithm>
#include <gtest/gtest.h>

#include "ch19/counted_element.h"
#include "doubly_linked_list_v4.h"

class DoublyLinkedListV4Test : public ::testing::Test {
protected:
    list<double> l_ = {0.0, 1.1, 2.2, 3.3, 4.4};
};

// for testing list of class without default
struct No_default {
    No_default(int) {}
};

TEST_F(DoublyLinkedListV4Test, DefaultConstructor) {
    list<double> l;
    EXPECT_EQ(l.size(), 0);
}

TEST_F(DoublyLinkedListV4Test, Constructor) {
    list<double> ld(3);
    EXPECT_EQ(ld.size(), 3);
    for (double d : ld)
        EXPECT_DOUBLE_EQ(d, 0);

    list<int> li(5, 8);
    EXPECT_EQ(li.size(), 5);
    for (int i : li)
        EXPECT_EQ(i, 8);

    // class without default
    list<No_default> ln(10, No_default(8));
    EXPECT_EQ(ln.size(), 10);

    // class with resources
    list<Counted_element> le(10);
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(DoublyLinkedListV4Test, InitializerListConstructor) {
    list<double> ld = {1, 2, 3};
    double expected[] = {1, 2, 3};
    EXPECT_EQ(ld.size(), 3);
    EXPECT_TRUE(std::equal(ld.begin(), ld.end(), expected));

    // class with resources
    list<Counted_element> le = {Counted_element(), Counted_element(), Counted_element()};
    EXPECT_EQ(Counted_element::count(), 3);
}

TEST_F(DoublyLinkedListV4Test, CopyConstructor) {
    list<double> l2 = l_;
    EXPECT_EQ(l2.size(), l_.size());
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), l_.begin()));
    *std::next(l_.begin()) = 99;
    l2.front() = 88;
    EXPECT_DOUBLE_EQ(l_.front(), 0);
    EXPECT_DOUBLE_EQ(*std::next(l2.begin()), 1.1);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    list<Counted_element> le2 = le;
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(DoublyLinkedListV4Test, CopyAssignment) {
    // self-assignment
    l_ = l_;
    double expected[] = {0.0, 1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(l_.size(), 5);
    EXPECT_TRUE(std::equal(l_.begin(), l_.end(), expected));

    list<double> l2 = {1, 2, 3};
    l2 = l_;
    EXPECT_EQ(l2.size(), l_.size());
    for (int i = 0; i < l2.size(); ++i)
        EXPECT_TRUE(std::equal(l2.begin(), l2.end(), l_.begin()));
    *std::next(l_.begin()) = 99;
    l2.front() = 88;
    EXPECT_DOUBLE_EQ(l_.front(), 0);
    EXPECT_DOUBLE_EQ(*std::next(l2.begin()), 1.1);

    // class with resources
    list<Counted_element> le(5), le2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    le2 = le;
    EXPECT_EQ(Counted_element::count(), 10);
}

TEST_F(DoublyLinkedListV4Test, MoveConstructor) {
    int size = l_.size();
    list<double> l2 = std::move(l_);
    double expected[] = {0.0, 1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(l2.size(), size);
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), expected));
    EXPECT_EQ(l_.size(), 0);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    list<Counted_element> le2 = std::move(le);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST_F(DoublyLinkedListV4Test, MoveAssignment) {
    list<double> l2 = {1, 2, 3};
    int size = l_.size();
    l2 = std::move(l_);
    double expected[] = {0.0, 1.1, 2.2, 3.3, 4.4};
    EXPECT_EQ(l2.size(), size);
    EXPECT_TRUE(std::equal(l2.begin(), l2.end(), expected));
    EXPECT_EQ(l_.size(), 0);

    // class with resources
    list<Counted_element> le(5), le2(8);
    EXPECT_EQ(Counted_element::count(), 13);
    le2 = std::move(le);
    EXPECT_EQ(Counted_element::count(), 5);
}

TEST_F(DoublyLinkedListV4Test, Destructor) {
    // class with resources
    auto ple = new list<Counted_element>(8);
    EXPECT_EQ(Counted_element::count(), 8);
    delete ple;
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST_F(DoublyLinkedListV4Test, Iterator) {
    auto it = std::find(l_.begin(), l_.end(), 3.3);
    EXPECT_NE(it, l_.end());
    EXPECT_DOUBLE_EQ(*it, 3.3);
    EXPECT_EQ(std::find(l_.begin(), l_.end(), 9.9), l_.end());

    double a[5];
    std::copy(l_.begin(), l_.end(), a);
    EXPECT_TRUE(std::equal(l_.begin(), l_.end(), a));
}

TEST_F(DoublyLinkedListV4Test, Size) {
    EXPECT_EQ(l_.size(), 5);
}

TEST_F(DoublyLinkedListV4Test, Insert) {
    // empty list
    list<double> l0;
    auto p = l0.insert(l0.end(), 42);
    EXPECT_EQ(p, l0.begin());
    EXPECT_DOUBLE_EQ(*p, 42);
    EXPECT_EQ(l0.size(), 1);

    // insert at middle
    p = l_.insert(std::next(l_.begin(), 4), 42);
    EXPECT_EQ(std::distance(l_.begin(), p), 4);
    EXPECT_DOUBLE_EQ(*p, 42);
    EXPECT_EQ(l_.size(), 6);

    // insert at end()
    p = l_.insert(l_.end(), 5.5);
    EXPECT_EQ(std::distance(l_.begin(), p), 6);
    EXPECT_DOUBLE_EQ(*p, 5.5);
    EXPECT_EQ(l_.size(), 7);

    // insert at begin()
    p = l_.insert(l_.begin(), -1.1);
    EXPECT_EQ(p, l_.begin());
    EXPECT_DOUBLE_EQ(*p, -1.1);
    EXPECT_EQ(l_.size(), 8);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.insert(std::next(le.begin(), 2), Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(DoublyLinkedListV4Test, Erase) {
    // empty list
    list<double> l0;
    EXPECT_EQ(l0.erase(l0.end()), l0.end());

    // erase end()
    EXPECT_EQ(l_.erase(l_.end()), l_.end());
    EXPECT_EQ(l_.size(), 5);

    // erase last element
    auto p = l_.erase(std::next(l_.begin(), 4));
    EXPECT_EQ(p, l_.end());
    EXPECT_EQ(l_.size(), 4);

    // erase first element
    p = l_.erase(l_.begin());
    EXPECT_EQ(p, l_.begin());
    EXPECT_DOUBLE_EQ(*p, 1.1);
    EXPECT_EQ(l_.size(), 3);

    // erase middle element
    p = l_.erase(std::next(l_.begin()));
    EXPECT_EQ(p, std::next(l_.begin()));
    EXPECT_DOUBLE_EQ(*p, 3.3);
    EXPECT_EQ(l_.size(), 2);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.erase(std::next(le.begin(), 2));
    EXPECT_EQ(Counted_element::count(), 4);
}

TEST_F(DoublyLinkedListV4Test, Clear) {
    // empty list
    list<double> l0;
    l0.clear();
    EXPECT_EQ(l0.size(), 0);

    // non-empty list
    l_.clear();
    EXPECT_EQ(l_.size(), 0);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.clear();
    EXPECT_EQ(Counted_element::count(), 0);
}

TEST_F(DoublyLinkedListV4Test, PushBack) {
    // empty list
    list<double> l0;
    l0.push_back(42);
    EXPECT_EQ(l0.size(), 1);
    EXPECT_DOUBLE_EQ(l0.back(), 42);

    // non-empty list
    l_.push_back(5.5);
    EXPECT_EQ(l_.size(), 6);
    EXPECT_DOUBLE_EQ(l_.back(), 5.5);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.push_back(Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(DoublyLinkedListV4Test, PopBack) {
    l_.pop_back();
    EXPECT_EQ(l_.size(), 4);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.pop_back();
    EXPECT_EQ(Counted_element::count(), 4);
}

TEST_F(DoublyLinkedListV4Test, PushFront) {
    // empty list
    list<double> l0;
    l0.push_front(42);
    EXPECT_EQ(l0.size(), 1);
    EXPECT_DOUBLE_EQ(l0.front(), 42);

    // non-empty list
    l_.push_front(5.5);
    EXPECT_EQ(l_.size(), 6);
    EXPECT_DOUBLE_EQ(l_.front(), 5.5);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.push_front(Counted_element());
    EXPECT_EQ(Counted_element::count(), 6);
}

TEST_F(DoublyLinkedListV4Test, PopFront) {
    l_.pop_front();
    EXPECT_EQ(l_.size(), 4);

    // class with resources
    list<Counted_element> le(5);
    EXPECT_EQ(Counted_element::count(), 5);
    le.pop_front();
    EXPECT_EQ(Counted_element::count(), 4);
}
