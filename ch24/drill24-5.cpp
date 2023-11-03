#include <iostream>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

// (1) Read ten floating-point values from input and put them into a Matrix<double>, print out the Matrix.
// (2) Read six ints into a Matrix<int,2> m(2,3) and print them out.
int main() {
    Matrix<double> a(10);
    for (Index i = 0; i < 10; ++i)
        cin >> a(i);
    cout << a << '\n';

    Matrix<int, 2> m(2, 3);
    for (Index i = 0; i < m.dim1(); ++i)
        for (Index j = 0; j < m.dim2(); ++j)
            cin >> m(i, j);
    cout << m << '\n';
    return 0;
}
