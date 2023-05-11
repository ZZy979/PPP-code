#include <gtest/gtest.h>
#include <string>

#include "doubly_linked_list_v2.h"

class DoublyLinkedListV2Test : public ::testing::Test {
protected:
    DoublyLinkedListV2Test() {
        // head -> a -> b -> c
        head_ = (new Link("c"))->insert(new Link("b"))->insert(new Link("a"));
    }

    ~DoublyLinkedListV2Test() {
        while (head_) {
            Link* next = head_->next();
            delete head_;
            head_ = next;
        }
    }

    Link* head_ = nullptr;
};

TEST_F(DoublyLinkedListV2Test, Insert) {
    EXPECT_EQ(head_->insert(nullptr), head_);

    // head -> a -> d -> b -> c
    Link* d = new Link("d");
    EXPECT_EQ(head_->next()->insert(d), d);
    EXPECT_EQ(d->previous()->value, "a");
    EXPECT_EQ(d->next()->value, "b");
    EXPECT_EQ(d->previous()->next(), d);
    EXPECT_EQ(d->next()->previous(), d);

    // head -> e -> a -> d -> b -> c
    Link* e = new Link("e");
    head_ = head_->insert(e);
    EXPECT_EQ(head_, e);
    EXPECT_EQ(e->previous(), nullptr);
    EXPECT_EQ(e->next()->value, "a");
    EXPECT_EQ(e->next()->previous(), e);
}

TEST_F(DoublyLinkedListV2Test, Add) {
    EXPECT_EQ(head_->add(nullptr), head_);

    // head -> a -> b -> d -> c
    Link* d = new Link("d");
    EXPECT_EQ(head_->next()->add(d), d);
    EXPECT_EQ(d->previous()->value, "b");
    EXPECT_EQ(d->next()->value, "c");
    EXPECT_EQ(d->previous()->next(), d);
    EXPECT_EQ(d->next()->previous(), d);

    // head -> a -> b -> d -> c -> e
    Link* e = new Link("e");
    EXPECT_EQ(d->next()->add(e), e);
    EXPECT_EQ(e->previous()->value, "c");
    EXPECT_EQ(e->next(), nullptr);
    EXPECT_EQ(e->previous()->next(), e);
}

TEST_F(DoublyLinkedListV2Test, Erase) {
    Link* a = head_;
    Link* c = head_->next()->next();

    // head -> d -> e -> a -> b -> c
    Link* e = head_->insert(new Link("e"));
    Link* d = head_ = e->insert(new Link("d"));

    // head -> d -> e -> b -> c
    Link* b = a->erase();
    EXPECT_EQ(b->value, "b");
    EXPECT_EQ(b->previous()->value, "e");
    EXPECT_EQ(b->next()->value, "c");
    EXPECT_EQ(b->previous()->next(), b);
    EXPECT_EQ(b->next()->previous(), b);
    delete a;

    // head -> d -> e -> b
    Link* n = c->erase();
    EXPECT_EQ(n, nullptr);
    EXPECT_EQ(b->next(), nullptr);

    // head -> e -> b
    head_ = d->erase();
    EXPECT_EQ(head_, e);
    EXPECT_EQ(e->previous(), nullptr);
    EXPECT_EQ(e->next()->value, "b");
    EXPECT_EQ(e->next()->previous(), e);
    delete d;
}

TEST_F(DoublyLinkedListV2Test, Find) {
    Link* p = head_->find("b");
    EXPECT_NE(p, nullptr);
    EXPECT_EQ(p->value, "b");

    EXPECT_EQ(head_->find("d"), nullptr);
    EXPECT_EQ(head_->next()->find("a"), nullptr);
}

TEST_F(DoublyLinkedListV2Test, Advance) {
    EXPECT_EQ(head_->advance(0), head_);
    EXPECT_EQ(head_->advance(2)->value, "c");
    EXPECT_EQ(head_->advance(5), nullptr);
    EXPECT_EQ(head_->next()->next()->advance(-1)->value, "b");
    EXPECT_EQ(head_->next()->next()->advance(-3), nullptr);
}
