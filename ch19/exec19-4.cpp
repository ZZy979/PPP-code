#include <iostream>
#include <regex>
#include <string>

#include "ch17/god.h"
#include "doubly_linked_list_v3.h"

using namespace std;

// Read gods (name, mythology, vehicle, weapon) of three mythologies from a text file and make a list,
// then move the gods from that list to three lexicographically ordered lists - one for each mythology.
int main() {
    regex re(R"(\((.+),(.+),(.+),(.+)\))");
    string line;
    auto gods = new Link<God>({});
    while (getline(cin, line)) {
        smatch m;
        if (regex_match(line, m, re))
            gods->add(new Link<God>({m[1].str(), m[2].str(), m[3].str(), m[4].str()}));
    }

    auto norse_gods = new Link<God>({});
    auto greek_gods = new Link<God>({});
    auto egyptian_gods = new Link<God>({});
    while (gods->next()) {
        Link<God>* p = gods->next();
        p->erase();
        if (p->value.mythology == "Norse")
            norse_gods->add_ordered(p);
        else if (p->value.mythology == "Greek")
            greek_gods->add_ordered(p);
        else
            egyptian_gods->add_ordered(p);
    }

    cout << "Norse gods:\n" << norse_gods->next()
            << "\nGreek gods:\n" << greek_gods->next()
            << "\nEgyptian gods:\n" << egyptian_gods->next();

    destroy(gods);
    destroy(norse_gods);
    destroy(greek_gods);
    destroy(egyptian_gods);
    return 0;
}
