#pragma once

// singly-linked list node
template<class Elem>
struct Link {
    Link* succ;
    Elem val;
};

// singly-linked list
template<class Elem>
class slist {
    class iterator;

    slist() :first(nullptr), sz(0) {}

    ~slist() {
        while (first) {
            auto next = first->succ;
            delete first;
            first = next;
        }
    }

    // iterator to first element
    iterator begin() { return iterator(first); }

    // iterator to one beyond last element
    iterator end() { return iterator(nullptr); }

    iterator insert_after(iterator p, const Elem& v); // insert v into list after p
    iterator erase_after(iterator p);                 // remove the element after p from the list

    void push_front(const Elem& v);     // insert v at front
    void pop_front();   // remove the first element

    Elem& front();  // the first element

    int size() const { return sz; };

private:
    Link<Elem>* first;
    int sz;
};

template<class Elem>
class slist<Elem>::iterator {
public:
    explicit iterator(Link<Elem>* p) :curr(p) {}
    iterator& operator++() { curr = curr->succ; return *this; }  // forward
    Elem& operator*() { return curr->val; }  // get value (dereference)
    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }

private:
    Link<Elem>* curr;  // current link
};

template<class Elem>
void slist<Elem>::push_front(const Elem& v) {
    if (!first)
        first = new Link<Elem>{nullptr, nullptr, v};
    else
        first = first->prev = new Link<Elem>{nullptr, first, v};
    ++sz;
}
