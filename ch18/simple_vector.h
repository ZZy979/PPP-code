#pragma once

#include <algorithm>
#include <initializer_list>

// a very simplified vector of doubles
class vector {
public:
    // constructor: allocate s elements, let elem point to them, store s in sz
    vector(int s) :sz(s), elem(new double[s]{0}) {}

    // initializer-list constructor
    vector(std::initializer_list<double> lst) :sz(lst.size()), elem(new double[sz]) {
        std::copy(lst.begin(), lst.end(), elem);    // initialize (using std::copy())
    }

    // destructor: free memory
    ~vector() { delete[] elem; }

    int size() const { return sz; }  // the current size

    double get(int n) { return elem[n]; }       // access: read
    void set(int n, double v) { elem[n] = v; }  // access: write

private:
    int sz;        // the size
    double* elem;  // pointer to the elements
};
