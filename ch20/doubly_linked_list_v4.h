#pragma once

// doubly-linked list node
template<class Elem>
struct Link {
    Link* prev;     // previous link
    Link* succ;     // successor (next) link
    Elem val;       // the value
};

// doubly-linked list
template<class Elem>
class list {
public:
    class iterator;     // member type: iterator

    iterator begin();   // iterator to first element
    iterator end();     // iterator to one beyond last element

    iterator insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);                 // remove p from the list

    void push_back(const Elem& v);      // insert v at end
    void push_front(const Elem& v);     // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element

    Elem& front();  // the first element
    Elem& back();   // the last element

    // ...

private:
    Link<Elem>* first;
    Link<Elem>* last;   // one beyond the last link
};

template<class Elem>
class list<Elem>::iterator {
public:
    explicit iterator(Link<Elem>* p) :curr(p) {}
    iterator& operator++() { curr = curr->succ; return *this; }  // forward
    iterator& operator--() { curr = curr->prev; return *this; }  // backward
    Elem& operator*() { return curr->val; }  // get value (dereference)
    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }

private:
    Link<Elem>* curr;  // current link
};
