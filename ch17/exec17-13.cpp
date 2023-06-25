#include <iostream>
#include <regex>
#include <string>

#include "god.h"

using namespace std;

// doubly-linked list node
class Link {
public:
    God value;

    Link(const God& v, Link* p = nullptr, Link* s = nullptr)
            :value(v), prev(p), succ(s) {}

    Link* insert(Link* n);
    Link* add(Link* n);
    Link* add_ordered(Link* n);
    Link* erase();

    Link* next() const { return succ; }
    Link* previous() const { return prev; }

private:
    Link* prev;
    Link* succ;
};

void print_all(Link* p);
void destroy(Link* p);

// Read gods (name, mythology, vehicle, weapon) of three mythologies from a text file and make a list,
// then move the gods from that list to three lexicographically ordered lists - one for each mythology.
int main() {
    regex re(R"(\((.+),(.+),(.+),(.+)\))");
    string line;
    Link* gods = new Link({});
    while (getline(cin, line)) {
        smatch m;
        if (regex_match(line, m, re))
            gods->add(new Link({m[1].str(), m[2].str(), m[3].str(), m[4].str()}));
    }

    Link* norse_gods = new Link({});
    Link* greek_gods = new Link({});
    Link* egyptian_gods = new Link({});
    while (gods->next()) {
        Link* p = gods->next();
        p->erase();
        if (p->value.mythology == "Norse")
            norse_gods->add_ordered(p);
        else if (p->value.mythology == "Greek")
            greek_gods->add_ordered(p);
        else
            egyptian_gods->add_ordered(p);
    }

    cout << "Norse gods:\n";
    print_all(norse_gods->next());
    cout << "\nGreek gods:\n";
    print_all(greek_gods->next());
    cout << "\nEgyptian gods:\n";
    print_all(egyptian_gods->next());

    destroy(gods);
    destroy(norse_gods);
    destroy(greek_gods);
    destroy(egyptian_gods);
    return 0;
}

// insert n before this object; return n
Link* Link::insert(Link* n) {
    if (n == nullptr) return this;
    n->succ = this;
    if (prev) prev->succ = n;
    n->prev = prev;
    prev = n;
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

// insert n in correct lexicographical position; return n
Link* Link::add_ordered(Link* n) {
    if (n == nullptr) return this;
    if (n->value.name < value.name)
        return insert(n);

    Link* p = this;
    while (p->next() && p->next()->value.name <= n->value.name)
        p = p->next();
    return p->add(n);
}

// remove this object from list; return this object's successor
Link* Link::erase() {
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

void print_all(Link* p) {
    for (; p; p = p->next())
        cout << p->value << endl;
}

void destroy(Link* p) {
    while (p) {
        Link* next = p->next();
        delete p;
        p = next;
    }
}
