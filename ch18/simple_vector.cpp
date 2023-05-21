#include "simple_vector.h"

// move constructor
vector::vector(vector&& v)
        :sz(v.sz), elem(v.elem) {   // copy v's elem and sz
    v.sz = 0;   // make v the empty vector
    v.elem = nullptr;
}

// copy assignment: make this vector a copy of v
vector& vector::operator=(const vector& v) {
    double* p = new double[v.sz];           // allocate new space
    std::copy(v.elem, v.elem + v.sz, p);    // copy elements
    delete[] elem;  // deallocate old space
    elem = p;       // now we can reset elem
    sz = v.sz;
    return *this;   // return a self-reference
}

// move assignment: move v to this vector
vector& vector::operator=(vector&& v) {
    delete[] elem;      // deallocate old space
    elem = v.elem;      // copy v's elem and sz
    sz = v.sz;
    v.elem = nullptr;   // make v the empty vector
    v.sz = 0;
    return *this;       // return a self-reference
}
