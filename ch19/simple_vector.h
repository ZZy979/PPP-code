#pragma once

#include <algorithm>
#include <initializer_list>

/**
 * An almost real vector of doubles
 *
 * invariant:
 * - if 0<=n<sz, elem[n] is element n
 * - sz<=space
 * - if sz<space there is space for (space–sz) doubles after elem[sz–1]
 */
class vector {
public:
    // default constructor
    vector() :sz(0), elem(nullptr), space(0) {}

    // constructor: allocate s elements, let elem point to them, store s in sz
    explicit vector(int s) :sz(s), elem(new double[s]{0}), space(s) {}

    // initializer-list constructor
    vector(std::initializer_list<double> lst)
            :sz(lst.size()), elem(new double[sz]), space(lst.size()) {
        std::copy(lst.begin(), lst.end(), elem);    // initialize (using std::copy())
    }

    vector(const vector& v);                // copy constructor
    vector& operator=(const vector& v);     // copy assignment

    vector(vector&& v) noexcept;            // move constructor
    vector& operator=(vector&& v) noexcept; // move assignment

    ~vector() { delete[] elem; }            // destructor: free memory

    double& operator[](int i) { return elem[i]; }       // for non-const vectors
    double operator[](int i) const { return elem[i]; }  // for const vectors

    int size() const { return sz; }         // the current size
    int capacity() const { return space; }  // the current capacity

    void reserve(int new_space);
    void resize(int new_size);
    void push_back(double d);

private:
    int sz;        // the size
    double* elem;  // pointer to the elements
    int space;     // number of elements plus number of free slots
};
