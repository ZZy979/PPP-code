#include <gtest/gtest.h>
#include <string>

#include "doubly_linked_list.h"

class DoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedListTest() {
        // head -> a -> b -> c
        for (const std::string& s : {"c", "b", "a"}) {
            head_ = insert(head_, new Link(s));
        }
    }

    ~DoublyLinkedListTest() {
        while (head_) {
            Link* next = head_->succ;
            delete head_;
            head_ = next;
        }
    }

    Link* head_ = nullptr;
};

TEST_F(DoublyLinkedListTest, Insert) {
    EXPECT_EQ(insert(head_, nullptr), head_);

    Link* d = new Link("d");
    EXPECT_EQ(insert(nullptr, d), d);

    // head -> a -> d -> b -> c
    EXPECT_EQ(insert(head_->succ, d), d);
    EXPECT_EQ(d->prev->value, "a");
    EXPECT_EQ(d->succ->value, "b");
    EXPECT_EQ(d->prev->succ, d);
    EXPECT_EQ(d->succ->prev, d);

    // head -> e -> a -> d -> b -> c
    Link* e = new Link("e");
    head_ = insert(head_, e);
    EXPECT_EQ(head_, e);
    EXPECT_EQ(e->prev, nullptr);
    EXPECT_EQ(e->succ->value, "a");
    EXPECT_EQ(e->succ->prev, e);
}

TEST_F(DoublyLinkedListTest, Add) {
    EXPECT_EQ(add(head_, nullptr), head_);

    Link* d = new Link("d");
    EXPECT_EQ(add(nullptr, d), d);

    // head -> a -> b -> d -> c
    EXPECT_EQ(add(head_->succ, d), d);
    EXPECT_EQ(d->prev->value, "b");
    EXPECT_EQ(d->succ->value, "c");
    EXPECT_EQ(d->prev->succ, d);
    EXPECT_EQ(d->succ->prev, d);

    // head -> a -> b -> d -> c -> e
    Link* e = new Link("e");
    EXPECT_EQ(add(d->succ, e), e);
    EXPECT_EQ(e->prev->value, "c");
    EXPECT_EQ(e->succ, nullptr);
    EXPECT_EQ(e->prev->succ, e);
}

TEST_F(DoublyLinkedListTest, Erase) {
    Link* a = head_;
    Link* c = head_->succ->succ;

    // head -> d -> e -> a -> b -> c
    Link* e = insert(head_, new Link("e"));
    Link* d = head_ = insert(e, new Link("d"));

    EXPECT_EQ(erase(nullptr), nullptr);
    
    // head -> d -> e -> b -> c
    Link* b = erase(a);
    EXPECT_EQ(b->value, "b");
    EXPECT_EQ(b->prev->value, "e");
    EXPECT_EQ(b->succ->value, "c");
    EXPECT_EQ(b->prev->succ, b);
    EXPECT_EQ(b->succ->prev, b);
    delete a;

    // head -> d -> e -> b
    Link* n = erase(c);
    EXPECT_EQ(n, nullptr);
    EXPECT_EQ(b->succ, nullptr);

    // head -> e -> b
    head_ = erase(d);
    EXPECT_EQ(head_, e);
    EXPECT_EQ(e->prev, nullptr);
    EXPECT_EQ(e->succ->value, "b");
    EXPECT_EQ(e->succ->prev, e);
    delete d;
}

TEST_F(DoublyLinkedListTest, Find) {
    Link* p = find(head_, "b");
    EXPECT_NE(p, nullptr);
    EXPECT_EQ(p->value, "b");

    EXPECT_EQ(find(head_, "d"), nullptr);
    EXPECT_EQ(find(head_->succ, "a"), nullptr);
    EXPECT_EQ(find(nullptr, "b"), nullptr);
}

TEST_F(DoublyLinkedListTest, Advance) {
    EXPECT_EQ(advance(nullptr, 1), nullptr);
    EXPECT_EQ(advance(head_, 0), head_);
    EXPECT_EQ(advance(head_, 2)->value, "c");
    EXPECT_EQ(advance(head_, 5), nullptr);
    EXPECT_EQ(advance(head_->succ->succ, -1)->value, "b");
    EXPECT_EQ(advance(head_->succ->succ, -3), nullptr);
}
