#include <iostream>

#include "doubly_linked_list.h"

using namespace std;

void print_all(Link* p);
void destroy(Link* p);

// linked list example: print names of Norse gods and Greek gods
int main() {
    Link* norse_gods = new Link("Thor");
    norse_gods = insert(norse_gods, new Link("Odin"));
    norse_gods = insert(norse_gods, new Link("Zeus"));
    norse_gods = insert(norse_gods, new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = insert(greek_gods, new Link("Athena"));
    greek_gods = insert(greek_gods, new Link("Mars"));
    greek_gods = insert(greek_gods, new Link("Poseidon"));

    if (Link* p = find(greek_gods, "Mars"))
        p->value = "Ares";

    if (Link* p = find(norse_gods, "Zeus")) {
        if (p == norse_gods) norse_gods = p->succ;
        erase(p);
        greek_gods = insert(greek_gods, p);
    }

    print_all(norse_gods);
    cout << '\n';
    print_all(greek_gods);
    cout << '\n';

    destroy(norse_gods);
    destroy(greek_gods);
    return 0;
}

void print_all(Link* p) {
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p = p->succ) cout << ", ";
    }
    cout << " }";
}

void destroy(Link* p) {
    while (p) {
        Link* next = p->succ;
        delete p;
        p = next;
    }
}
