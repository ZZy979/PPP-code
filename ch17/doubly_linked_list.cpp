#include "doubly_linked_list.h"

// insert n before p; return n
Link* insert(Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;
    n->succ = p;            // p comes after n
    if (p->prev) p->prev->succ = n;  // n comes after what used to be p's predecessor
    n->prev = p->prev;      // p's predecessor becomes n's predecessor
    p->prev = n;            // n becomes p's predecessor
    return n;
}

// insert n after p; return n
Link* add(Link* p, Link* n) {
    if (n == nullptr) return p;
    if (p == nullptr) return n;
    n->succ = p->succ;
    n->prev = p;
    if (p->succ) p->succ->prev = n;
    p->succ = n;
    return n;
}

// remove *p from list; return p's successor
Link* erase(Link* p) {
    if (p == nullptr) return nullptr;
    if (p->succ) p->succ->prev = p->prev;
    if (p->prev) p->prev->succ = p->succ;
    return p->succ;
}

// find s in list; return nullptr for "not found"
Link* find(Link* p, const std::string& s) {
    while (p) {
        if (p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

// move n positions in list; return nullptr for "not found"
// positive n moves forward, negative backward
Link* advance(Link* p, int n) {
    if (p == nullptr) return nullptr;
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
