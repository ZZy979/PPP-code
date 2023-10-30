#pragma once

#include <stdexcept>

#include "Matrix.h"

using Matrix = Numeric_lib::Matrix<double, 2>;
using Vector = Numeric_lib::Matrix<double, 1>;

// An exception of this type is thrown when elimination fails.
struct Elim_failure : std::domain_error {
    using std::domain_error::domain_error;
};

// An exception of this type is thrown when back substitution fails.
struct Back_subst_failure : std::domain_error {
    using std::domain_error::domain_error;
};

Vector classical_gaussian_elimination(Matrix A, Vector b);
Vector pivotal_elimination(Matrix A, Vector b);

void classical_elimination(Matrix& A, Vector& b);
Vector back_substitution(const Matrix& A, const Vector& b);
void elim_with_partial_pivot(Matrix& A, Vector& b);

Vector operator*(const Matrix& m, const Vector& u);
