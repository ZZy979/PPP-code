#include <iostream>

#include "doubly_linked_list_v2.h"

using namespace std;

void print_all(Link* p);
void destroy(Link* p);

// linked list example: print names of Norse gods and Greek gods
int main() {
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));

    if (Link* p = greek_gods->find("Mars"))
        p->value = "Ares";

    if (Link* p = norse_gods->find("Zeus")) {
        if (p == norse_gods) norse_gods = p->next();
        p->erase();
        greek_gods = greek_gods->insert(p);
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
        if (p = p->next()) cout << ", ";
    }
    cout << " }";
}

void destroy(Link* p) {
    while (p) {
        Link* next = p->next();
        delete p;
        p = next;
    }
}
