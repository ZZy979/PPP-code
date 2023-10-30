#include <iostream>

#include "MatrixIO.h"
#include "gaussian_elimination.h"

using namespace std;
using Numeric_lib::Index;

// Read matrix A and vector b from input, solve and output x, s.t. Ax = b.
int main() {
    try {
        Index n;
        cin >> n;

        Matrix A(n, n);
        Vector b(n);
        cin >> A >> b;

        Vector x = pivotal_elimination(A, b);
        cout << x << '\n';
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
