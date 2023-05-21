#include "simple_vector.h"

// copy assignment: make this vector a copy of v
vector& vector::operator=(const vector& v) {
    double* p = new double[v.sz];           // allocate new space
    std::copy(v.elem, v.elem + v.sz, p);    // copy elements
    delete[] elem;  // deallocate old space
    elem = p;       // now we can reset elem
    sz = v.sz;
    return *this;   // return a self-reference
}
