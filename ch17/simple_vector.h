#pragma once

// a very simplified vector of doubles
class vector {
public:
    // constructor: allocate s elements, let elem point to them, store s in sz
    vector(int s) :sz(s), elem(new double[s]{0}) {}

    // destructor: free memory
    ~vector() { delete[] elem; }

    int size() const { return sz; }  // the current size

    double get(int n) { return elem[n]; }       // access: read
    void set(int n, double v) { elem[n] = v; }  // access: write

private:
    int sz;        // the size
    double* elem;  // pointer to the elements
};
