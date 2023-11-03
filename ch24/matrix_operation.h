#pragma once

#include <functional>

#include "Matrix/Matrix.h"

namespace Numeric_lib {

// matrix-vector multiplication
template<class T>
Matrix<T> mm(const Matrix<T, 2>& a, const Matrix<T>& v) {
    if (a.dim2() != v.dim1())
        throw Matrix_error("a.dim2() must be equal to v.dim1()");

    Matrix<T> res(a.dim1());
    for (Index i = 0; i < a.dim1(); ++i)
        res(i) = dot_product(a[i], v);
    return res.xfer();
}

// matrix multiplication
template<class T>
Matrix<T, 2> mm(const Matrix<T, 2>& a, const Matrix<T, 2>& b) {
    if (a.dim2() != b.dim1())
        throw Matrix_error("a.dim2() must be equal to b.dim1()");

    Matrix<T, 2> res(a.dim1(), b.dim2());
    for (Index i = 0; i < a.dim1(); ++i)
        for (Index j = 0; j < b.dim2(); ++j)
            for (Index k = 0; k < a.dim2(); ++k)
                res(i, j) += a(i, k) * b(k, j);
    return res.xfer();
}

// check matrix shape
template<class T>
void check_same_shape(const Matrix<T>& a, const Matrix<T>& b) {
    if (a.dim1() != b.dim1())
        throw Matrix_error("a must have same shape as b");
}

template<class T>
void check_same_shape(const Matrix<T, 2>& a, const Matrix<T, 2>& b) {
    if (a.dim1() != b.dim1() || a.dim2() != b.dim2())
        throw Matrix_error("a must have same shape as b");
}

template<class T>
void check_same_shape(const Matrix<T, 3>& a, const Matrix<T, 3>& b) {
    if (a.dim1() != b.dim1() || a.dim2() != b.dim2() || a.dim3() != b.dim3())
        throw Matrix_error("a must have same shape as b");
}

// 1D matrix element-wise operation
template<class T, class F>
Matrix<T> apply(const Matrix<T>& a, const Matrix<T>& b, F f) {
    check_same_shape(a, b);
    Matrix<T> res(a.dim1());
    for (Index i = 0; i < a.dim1(); ++i)
        res(i) = f(a(i), b(i));
    return res.xfer();
}

template<class T> Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) { return apply(a, b, std::plus<T>()); }
template<class T> Matrix<T> operator-(const Matrix<T>& a, const Matrix<T>& b) { return apply(a, b, std::minus<T>()); }
template<class T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) { return apply(a, b, std::multiplies<T>()); }
template<class T> Matrix<T> operator/(const Matrix<T>& a, const Matrix<T>& b) { return apply(a, b, std::divides<T>()); }
template<class T> Matrix<T> operator%(const Matrix<T>& a, const Matrix<T>& b) { return apply(a, b, std::modulus<T>()); }

// 2D matrix element-wise operation
template<class T, class F>
Matrix<T, 2> apply(const Matrix<T, 2>& a, const Matrix<T, 2>& b, F f) {
    check_same_shape(a, b);
    Matrix<T, 2> res(a.dim1(), a.dim2());
    for (Index i = 0; i < a.dim1(); ++i)
        for (Index j = 0; j < a.dim2(); ++j)
            res(i, j) = f(a(i, j), b(i, j));
    return res.xfer();
}

template<class T> Matrix<T, 2> operator+(const Matrix<T, 2>& a, const Matrix<T, 2>& b) { return apply(a, b, std::plus<T>()); }
template<class T> Matrix<T, 2> operator-(const Matrix<T, 2>& a, const Matrix<T, 2>& b) { return apply(a, b, std::minus<T>()); }
template<class T> Matrix<T, 2> operator*(const Matrix<T, 2>& a, const Matrix<T, 2>& b) { return apply(a, b, std::multiplies<T>()); }
template<class T> Matrix<T, 2> operator/(const Matrix<T, 2>& a, const Matrix<T, 2>& b) { return apply(a, b, std::divides<T>()); }
template<class T> Matrix<T, 2> operator%(const Matrix<T, 2>& a, const Matrix<T, 2>& b) { return apply(a, b, std::modulus<T>()); }

// 3D matrix element-wise operation
template<class T, class F>
Matrix<T, 3> apply(const Matrix<T, 3>& a, const Matrix<T, 3>& b, F f) {
    check_same_shape(a, b);
    Matrix<T, 3> res(a.dim1(), a.dim2(), a.dim3());
    for (Index i = 0; i < a.dim1(); ++i)
        for (Index j = 0; j < a.dim2(); ++j)
            for (Index k = 0; k < a.dim3(); ++k)
                res(i, j, k) = f(a(i, j, k), b(i, j, k));
    return res.xfer();
}

template<class T> Matrix<T, 3> operator+(const Matrix<T, 3>& a, const Matrix<T, 3>& b) { return apply(a, b, std::plus<T>()); }
template<class T> Matrix<T, 3> operator-(const Matrix<T, 3>& a, const Matrix<T, 3>& b) { return apply(a, b, std::minus<T>()); }
template<class T> Matrix<T, 3> operator*(const Matrix<T, 3>& a, const Matrix<T, 3>& b) { return apply(a, b, std::multiplies<T>()); }
template<class T> Matrix<T, 3> operator/(const Matrix<T, 3>& a, const Matrix<T, 3>& b) { return apply(a, b, std::divides<T>()); }
template<class T> Matrix<T, 3> operator%(const Matrix<T, 3>& a, const Matrix<T, 3>& b) { return apply(a, b, std::modulus<T>()); }

// matrix comparison
template<class T>
bool operator==(const Matrix<T>& a, const Matrix<T>& b) {
    check_same_shape(a, b);
    for (Index i = 0; i < a.dim1(); ++i)
        if (a(i) != b(i)) return false;
    return true;
}

template<class T>
bool operator==(const Matrix<T, 2>& a, const Matrix<T, 2>& b) {
    check_same_shape(a, b);
    for (Index i = 0; i < a.dim1(); ++i)
        for (Index j = 0; j < a.dim2(); ++j)
            if (a(i, j) != b(i, j)) return false;
    return true;
}

template<class T>
bool operator==(const Matrix<T, 3>& a, const Matrix<T, 3>& b) {
    check_same_shape(a, b);
    for (Index i = 0; i < a.dim1(); ++i)
        for (Index j = 0; j < a.dim2(); ++j)
            for (Index k = 0; k < a.dim3(); ++k)
                if (a(i, j, k) != b(i, j, k)) return false;
    return true;
}

template<class T, int D> bool operator!=(const Matrix<T, D>& a, const Matrix<T, D>& b) { return !(a == b); }

}
