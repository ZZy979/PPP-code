#pragma once

#include <iostream>

// doubly-linked list node
template<class T>
class Link {
public:
    T value;

    explicit Link(const T& v, Link* p = nullptr, Link* s = nullptr)
            :value(v), prev(p), succ(s) {}

    Link* insert(Link* n);
    Link* add(Link* n);
    Link* add_ordered(Link* n);
    Link* erase();
    Link* find(const T& v);
    const Link* find(const T& v) const;
    Link* advance(int n);
    const Link* advance(int n) const;

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

private:
    Link* prev;
    Link* succ;
};

// insert n before this object; return n
template<class T>
Link<T>* Link<T>::insert(Link* n) {
    if (n == nullptr) return this;  // nothing to insert
    n->succ = this;                 // this object comes after n
    if (prev) prev->succ = n;       // n comes after what used to be p's predecessor
    n->prev = prev;                 // this object's predecessor becomes n's predecessor
    prev = n;                       // n becomes this object's predecessor
    return n;
}

// insert n after this object; return n
template<class T>
Link<T>* Link<T>::add(Link* n) {
    if (n == nullptr) return this;
    n->succ = succ;
    n->prev = this;
    if (succ) succ->prev = n;
    succ = n;
    return n;
}

// insert n in correct lexicographical position; return n
template<class T>
Link<T>* Link<T>::add_ordered(Link* n) {
    if (n == nullptr) return this;
    if (n->value < value)
        return insert(n);

    Link* p = this;
    while (p->next() && (p->next()->value < n->value || p->next()->value == n->value))
        p = p->next();
    return p->add(n);
}

// remove this object from list; return this object's successor
template<class T>
Link<T>* Link<T>::erase() {
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

// find v in list; return nullptr for "not found"
template<class T>
Link<T>* Link<T>::find(const T& v) {
    return const_cast<Link*>(static_cast<const Link*>(this)->find(v));
}

// find v in const list; return nullptr for "not found"
template<class T>
const Link<T>* Link<T>::find(const T& v) const {
    const Link* p = this;
    while (p) {
        if (p->value == v) return p;
        p = p->succ;
    }
    return nullptr;
}

// move n positions in list; return nullptr for "not found"
// positive n moves forward, negative backward
template<class T>
Link<T>* Link<T>::advance(int n) {
    return const_cast<Link*>(static_cast<const Link*>(this)->advance(n));
}

// move n positions in const list; return nullptr for "not found"
// positive n moves forward, negative backward
template<class T>
const Link<T>* Link<T>::advance(int n) const {
    const Link* p = this;
    if (n > 0) {
        while (n--) {
            if (p->succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}

template<class T>
std::ostream& operator<<(std::ostream& os, Link<T>* p) {
    for (; p; p = p->next())
        os << p->value << std::endl;
    return os;
}

template<class T>
void destroy(Link<T>* p) {
    while (p) {
        Link<T>* next = p->next();
        delete p;
        p = next;
    }
}
