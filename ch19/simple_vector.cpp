#include "simple_vector.h"

// copy constructor: define copy
vector::vector(const vector& v) :sz(v.sz), elem(new double[v.space]), space(v.space) {
    std::copy(v.elem, v.elem + sz, elem);
}

// copy assignment: make this vector a copy of v
vector& vector::operator=(const vector& v) {
    if (this == &v) return *this;   // self-assignment, no work needed

    if (v.sz <= space) {    // enough space, no need for new allocation
        std::copy(v.elem, v.elem + v.sz, elem);     // copy elements
        sz = v.sz;
        return *this;
    }

    double* p = new double[v.sz];           // allocate new space
    std::copy(v.elem, v.elem + v.sz, p);    // copy elements
    delete[] elem;      // deallocate old space
    elem = p;           // set new elements
    space = sz = v.sz;  // set new size
    return *this;       // return a self-reference
}

// move constructor
vector::vector(vector&& v) noexcept :sz(v.sz), elem(v.elem), space(v.space) {
    v.space = v.sz = 0;     // make v the empty vector
    v.elem = nullptr;
}

// move assignment: move v to this vector
vector& vector::operator=(vector&& v) noexcept {
    delete[] elem;      // deallocate old space
    elem = v.elem;      // copy v's elem and sz
    sz = v.sz;
    space = v.space;
    v.elem = nullptr;   // make v the empty vector
    v.space = v.sz = 0;
    return *this;       // return a self-reference
}

// increase the capacity
void vector::reserve(int new_space) {
    if (new_space <= space) return;     // never decrease allocation
    double* p = new double[new_space];  // allocate new space
    std::copy(elem, elem + sz, p);      // copy old elements
    delete[] elem;                      // deallocate old space
    elem = p;
    space = new_space;
}

// make the vector have new_size elements
// initialize each new element with the default value 0.0
void vector::resize(int new_size) {
    reserve(new_size);
    for (int i = sz; i < new_size; ++i) elem[i] = 0;    // initialize new elements
    sz = new_size;
}

// increase vector size by one; initialize the new element with d
void vector::push_back(double d) {
    if (space == 0)
        reserve(8);             // start with space for 8 elements
    else if (sz == space)
        reserve(2 * space);     // get more space
    elem[sz] = d;   // add d at end
    ++sz;           // increase the size (sz is the number of elements)
}
