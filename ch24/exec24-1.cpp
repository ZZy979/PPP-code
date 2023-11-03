#include <iostream>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

void triple_inplace(int& x) { x *= 3; }
int triple(int x) { return x * 3; }

template<class T>
struct TripleInplace {
    void operator()(T& x) { x *= 3; }
};

template<class T>
struct Triple {
    T operator()(T& x) { return x * 3; }
};

// Write a triple() function and use it to triple the elements of an array.
int main() {
    int val[] = {1, 2, 3, 4, 5};
    Matrix<int> a(val);
    a.apply(triple_inplace);
    cout << a << '\n';

    Matrix<int> b = apply(triple, a);
    cout << b << '\n';

    Matrix<int> a2(val);
    a2.apply(TripleInplace<int>());
    cout << a2 << '\n';

    Matrix<int> b2 = apply(Triple<int>(), a2);
    cout << b2 << '\n';
    return 0;
}
