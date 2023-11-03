#include <iostream>

#include "MatrixIO.h"
#include "gaussian_elimination.h"

using namespace std;

using Numeric_lib::Index;

void animate_gaussian_elimination(Matrix& A, Vector& b);

// Animate the Gaussian elimination.
int main() {
    try {
        Index n;
        cin >> n;

        Matrix A(n, n);
        Vector b(n);
        cin >> A >> b;
        animate_gaussian_elimination(A, b);
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}

void animate_gaussian_elimination(Matrix& A, Vector& b) {
    const Index n = A.dim1();

    // traverse from 1st column to the next-to-last
    // filling zeros into all elements under the diagonal:
    for (Index j = 0; j < n - 1; ++j) {
        cout << "\nStep " << j + 1 << '\n';
        const double pivot = A(j, j);
        if (pivot == 0) throw Elim_failure("Elimination failure in row " + std::to_string(j));

        // fill zeros into each element under the diagonal of the ith row:
        for (Index i = j + 1; i < n; ++i) {
            const double mult = A(i, j) / pivot;
            A[i].slice(j) = Numeric_lib::scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult * b(j);    // make the corresponding change to b
        }
        cout << "A = " << A << '\n';
        cout << "b = " << b << '\n';
    }
}
