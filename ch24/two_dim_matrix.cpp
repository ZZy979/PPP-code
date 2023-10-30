#include <iostream>

#include "Matrix.h"

using namespace std;
using namespace Numeric_lib;

// initialize each element to a characteristic value
void init(Matrix<int, 2>& a) {
    for (int i = 0; i < a.dim1(); ++i)
        for (int j = 0; j < a.dim2(); ++j)
            a(i, j) = 10 * i + j;
}

// print the elements row by row
void print(const Matrix<int, 2>& a) {
    for (int i = 0; i < a.dim1(); ++i) {
        for (int j = 0; j < a.dim2(); ++j)
            cout << a(i, j) << '\t';
        cout << '\n';
    }
}

int main() {
    Matrix<int, 2> a(3, 4);
    init(a);
    print(a);
    return 0;
}
