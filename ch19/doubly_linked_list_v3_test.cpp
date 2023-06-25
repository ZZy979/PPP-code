#include <gtest/gtest.h>

#include "doubly_linked_list_v3.h"

class DoublyLinkedListV3Test : public ::testing::Test {
protected:
    DoublyLinkedListV3Test() {
        // head -> a -> b -> c
        head_ = (new Link<char>('c'))->insert(new Link<char>('b'))->insert(new Link<char>('a'));
    }

    ~DoublyLinkedListV3Test() override {
        destroy(head_);
    }

    Link<char>* head_ = nullptr;
};

TEST_F(DoublyLinkedListV3Test, Insert) {
    EXPECT_EQ(head_->insert(nullptr), head_);

    // head -> a -> d -> b -> c
    auto d = new Link<char>('d');
    EXPECT_EQ(head_->next()->insert(d), d);
    EXPECT_EQ(d->previous()->value, 'a');
    EXPECT_EQ(d->next()->value, 'b');
    EXPECT_EQ(d->previous()->next(), d);
    EXPECT_EQ(d->next()->previous(), d);

    // head -> e -> a -> d -> b -> c
    auto e = new Link<char>('e');
    head_ = head_->insert(e);
    EXPECT_EQ(head_, e);
    EXPECT_EQ(e->previous(), nullptr);
    EXPECT_EQ(e->next()->value, 'a');
    EXPECT_EQ(e->next()->previous(), e);
}

TEST_F(DoublyLinkedListV3Test, Add) {
    EXPECT_EQ(head_->add(nullptr), head_);

    // head -> a -> b -> d -> c
    auto d = new Link<char>('d');
    EXPECT_EQ(head_->next()->add(d), d);
    EXPECT_EQ(d->previous()->value, 'b');
    EXPECT_EQ(d->next()->value, 'c');
    EXPECT_EQ(d->previous()->next(), d);
    EXPECT_EQ(d->next()->previous(), d);

    // head -> a -> b -> d -> c -> e
    auto e = new Link<char>('e');
    EXPECT_EQ(d->next()->add(e), e);
    EXPECT_EQ(e->previous()->value, 'c');
    EXPECT_EQ(e->next(), nullptr);
    EXPECT_EQ(e->previous()->next(), e);
}

TEST_F(DoublyLinkedListV3Test, AddOrdered) {
    // head -> a -> b -> c -> e
    auto e = new Link<char>('e');
    EXPECT_EQ(head_->add_ordered(e), e);
    EXPECT_EQ(e->previous()->value, 'c');
    EXPECT_EQ(e->next(), nullptr);
    EXPECT_EQ(e->previous()->next(), e);

    // head -> a -> b -> c -> d -> e
    auto d = new Link<char>('d');
    EXPECT_EQ(head_->add_ordered(d), d);
    EXPECT_EQ(d->previous()->value, 'c');
    EXPECT_EQ(d->next()->value, 'e');
    EXPECT_EQ(d->previous()->next(), d);
    EXPECT_EQ(d->next()->previous(), d);

    // head -> a -> a -> b -> c -> d -> e
    auto a2 = new Link<char>('a');
    EXPECT_EQ(head_->add_ordered(a2), a2);
    EXPECT_EQ(a2->previous()->value, 'a');
    EXPECT_EQ(a2->next()->value, 'b');
    EXPECT_EQ(a2->previous()->next(), a2);
    EXPECT_EQ(a2->next()->previous(), a2);
}

TEST_F(DoublyLinkedListV3Test, Erase) {
    Link<char>* a = head_;
    Link<char>* c = head_->next()->next();

    // head -> d -> e -> a -> b -> c
    Link<char>* e = head_->insert(new Link<char>('e'));
    Link<char>* d = head_ = e->insert(new Link<char>('d'));

    // head -> d -> e -> b -> c
    Link<char>* b = a->erase();
    EXPECT_EQ(b->value, 'b');
    EXPECT_EQ(b->previous()->value, 'e');
    EXPECT_EQ(b->next()->value, 'c');
    EXPECT_EQ(b->previous()->next(), b);
    EXPECT_EQ(b->next()->previous(), b);
    delete a;

    // head -> d -> e -> b
    Link<char>* n = c->erase();
    EXPECT_EQ(n, nullptr);
    EXPECT_EQ(b->next(), nullptr);

    // head -> e -> b
    head_ = d->erase();
    EXPECT_EQ(head_, e);
    EXPECT_EQ(e->previous(), nullptr);
    EXPECT_EQ(e->next()->value, 'b');
    EXPECT_EQ(e->next()->previous(), e);
    delete d;
}

TEST_F(DoublyLinkedListV3Test, Find) {
    Link<char>* p = head_->find('b');
    EXPECT_NE(p, nullptr);
    EXPECT_EQ(p->value, 'b');

    EXPECT_EQ(head_->find('d'), nullptr);
    EXPECT_EQ(head_->next()->find('a'), nullptr);
}

TEST_F(DoublyLinkedListV3Test, Advance) {
    EXPECT_EQ(head_->advance(0), head_);
    EXPECT_EQ(head_->advance(2)->value, 'c');
    EXPECT_EQ(head_->advance(5), nullptr);
    EXPECT_EQ(head_->next()->next()->advance(-1)->value, 'b');
    EXPECT_EQ(head_->next()->next()->advance(-3), nullptr);
}
