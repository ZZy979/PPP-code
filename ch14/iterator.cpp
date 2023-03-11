#include "iterator.h"

double* Vector_iterator::next() {
    return it == end ? nullptr : &(*it++);
}

double* List_iterator::next() {
    return it == end ? nullptr : &(*it++);
}

void print(std::ostream& os, Iterator& it) {
    for (double* p = it.next(); p; p = it.next())
        os << *p << ' ';
}
