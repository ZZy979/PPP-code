#include <iostream>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

void f(int n1, int n2, int n3) {
    Matrix<double, 1> ad1(n1);  // elements are doubles; one dimension
    Matrix<int, 1> ai1(n1);     // elements are ints; one dimension
    ad1(7) = 7;     // subscript using ( ) - Fortran style
    ai1[7] = 8;     // [ ] also works - C style
    cout << "ad1 = " << ad1 << ", ai2 = " << ai1 << '\n';

    Matrix<double, 2> ad2(n1, n2);      // 2-dimensional
    Matrix<double, 3> ad3(n1, n2, n3);  // 3-dimensional
    ad2(3, 4) = 7.5;        // true multidimensional subscripting
    ad3(3, 4, 5) = 9.2;
    cout << "ad2 =\n" << ad2 << '\n';
}

int main() {
    f(10, 5, 6);
    return 0;
}
