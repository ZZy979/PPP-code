#include "gaussian_elimination.h"

#include <cmath>
#include <string>

using Numeric_lib::Index;

Vector classical_gaussian_elimination(Matrix A, Vector b) {
    classical_elimination(A, b);
    return back_substitution(A, b);
}

Vector pivotal_elimination(Matrix A, Vector b) {
    elim_with_partial_pivot(A, b);
    return back_substitution(A, b);
}

void classical_elimination(Matrix& A, Vector& b) {
    const Index n = A.dim1();

    // traverse from 1st column to the next-to-last
    // filling zeros into all elements under the diagonal:
    for (Index j = 0; j < n - 1; ++j) {
        const double pivot = A(j, j);
        if (pivot == 0) throw Elim_failure("Elimination failure in row " + std::to_string(j));

        // fill zeros into each element under the diagonal of the ith row:
        for (Index i = j + 1; i < n; ++i) {
            const double mult = A(i, j) / pivot;
            A[i].slice(j) = Numeric_lib::scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult * b(j);    // make the corresponding change to b
        }
    }
}

Vector back_substitution(const Matrix& A, const Vector& b) {
    const Index n = A.dim1();
    Vector x(n);

    for (Index i = n - 1; i >= 0; --i) {
        double s = b(i) - Numeric_lib::dot_product(A[i].slice(i + 1), x.slice(i + 1));

        if (double m = A(i, i))
            x(i) = s / m;
        else
            throw Back_subst_failure("Back substitution failure in row " + std::to_string(i));
    }

    return x;
}

void elim_with_partial_pivot(Matrix& A, Vector& b) {
    const Index n = A.dim1();

    for (Index j = 0; j < n - 1; ++j) {
        Index pivot_row = j;

        // look for a suitable pivot:
        for (Index k = j + 1; k < n; ++k)
            if (fabs(A(k, j)) > fabs(A(pivot_row, j))) pivot_row = k;

        // swap the rows if we found a better pivot:
        if (pivot_row != j) {
            A.swap_rows(j, pivot_row);
            std::swap(b(j), b(pivot_row));
        }

        // elimination:
        for (Index i = j + 1; i < n; ++i) {
            const double pivot = A(j, j);
            if (pivot == 0) throw Elim_failure("Elimination failure in row " + std::to_string(j));
            const double mult = A(i, j) / pivot;
            A[i].slice(j) = Numeric_lib::scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult * b(j);
        }
    }
}

Vector operator*(const Matrix& m, const Vector& u) {
    const Index n = m.dim1();
    Vector v(n);
    for (Index i = 0; i < n; ++i) v(i) = dot_product(m[i], u);
    return v;
}
