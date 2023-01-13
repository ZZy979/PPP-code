#include "fill_vector.h"

// read integers from ist into v until we reach eof() or terminator
void fill_vector(std::istream& ist, std::vector<int>& v, char terminator) {
    ist.exceptions(std::ios_base::badbit);   // make ist throw if goes bad

    for (int i; ist >> i;) v.push_back(i);
    if (ist.eof()) return;   // fine: we found the end of file

    // not good() and not bad() and not eof(), ist must be fail()
    ist.clear();         // clear stream state, so that we can look for terminator

    char c;
    ist >> c;            // read a character, hopefully terminator
    if (c != terminator) {
        // ouch: not the terminator, so we must fail
        ist.unget();     // put that character back
        ist.clear(std::ios_base::failbit);   // set the state to fail()
    }
}
