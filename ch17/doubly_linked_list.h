#pragma once

#include <string>

// doubly-linked list node
struct Link {
    std::string value;
    Link* prev;
    Link* succ;

    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
            :value(v), prev(p), succ(s) {}
};

Link* insert(Link* p, Link* n);
Link* add(Link* p, Link* n);
Link* erase(Link* p);
Link* find(Link* p, const std::string& s);
Link* advance(Link* p, int n);
