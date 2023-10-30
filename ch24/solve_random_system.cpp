#include <cstdlib>
#include <iostream>

#include "MatrixIO.h"
#include "gaussian_elimination.h"

using namespace std;
using Numeric_lib::Index;

Vector random_vector(Index n);
Matrix random_matrix(Index n);
void solve_random_system(Index n);

// Solve random linear equations.
int main() {
    cout << "Enter number of equations: ";
    Index n;
    cin >> n;
    solve_random_system(n);
    return 0;
}

Vector random_vector(Index n) {
    Vector v(n);
    for (Index i = 0; i < n; ++i)
        v(i) = 1.0 * n * rand() / RAND_MAX;
    return v;
}

Matrix random_matrix(Index n) {
    Matrix m(n, n);
    for (Index i = 0; i < n; ++i)
        m[i] = random_vector(n);
    return m;
}

void solve_random_system(Index n) {
    Matrix A = random_matrix(n);
    Vector b = random_vector(n);

    cout << "A = " << A << endl;
    cout << "b = " << b << endl;

    try {
        Vector x = classical_gaussian_elimination(A, b);
        cout << "classical elim solution is x = " << x << endl;
        Vector v = A * x;
        cout << " A * x = " << v << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
}
