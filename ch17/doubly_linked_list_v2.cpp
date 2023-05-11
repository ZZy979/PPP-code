#include "doubly_linked_list_v2.h"

//insert n before this object; return n
Link* Link::insert(Link* n) {
    if (n == nullptr) return this;  // nothing to insert
    n->succ = this;                 // this object comes after n
    if (prev) prev->succ = n;       // n comes after what used to be p's predecessor
    n->prev = prev;                 // this object's predecessor becomes n's predecessor
    prev = n;                       // n becomes this object's predecessor
    return n;
}

// insert n after this object; return n
Link* Link::add(Link* n) {
    if (n == nullptr) return this;
    n->succ = succ;
    n->prev = this;
    if (succ) succ->prev = n;
    succ = n;
    return n;
}

// remove this object from list; return this object's successor
Link* Link::erase() {
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

// find s in list; return nullptr for "not found"
Link* Link::find(const std::string& s) {
    return const_cast<Link*>(static_cast<const Link*>(this)->find(s));
}

// find s in const list; return nullptr for "not found"
const Link* Link::find(const std::string& s) const {
    const Link* p = this;
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

// move n positions in list; return nullptr for "not found"
// positive n moves forward, negative backward
Link* Link::advance(int n) {
    return const_cast<Link*>(static_cast<const Link*>(this)->advance(n));
}

// move n positions in const list; return nullptr for "not found"
// positive n moves forward, negative backward
const Link* Link::advance(int n) const {
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
