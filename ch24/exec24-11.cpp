#include <iostream>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

template<class T>
class MyMatrix : public Matrix<T, 2> {
public:
    using Matrix<T, 2>::Matrix;

    void swap_columns(Index i, Index j) {
        if (i == j) return;
        for (Index r = 0; r < this->dim1(); ++r)
            swap((*this)(r, i), (*this)(r, j));
    }
};

int main() {
    int val[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    MyMatrix<int> m(val);
    m.swap_columns(1, 3);
    cout << m << '\n';
    return 0;
}
