#include <iostream>

#include "Matrix.h"

using namespace std;
using namespace Numeric_lib;

int main() {
    cout << "sizeof(char) == " << sizeof(char) << '\n';
    cout << "sizeof(short) == " << sizeof(short) << '\n';
    cout << "sizeof(int) == " << sizeof(int) << '\n';
    cout << "sizeof(long) == " << sizeof(long) << '\n';
    cout << "sizeof(float) == " << sizeof(float) << '\n';
    cout << "sizeof(double) == " << sizeof(double) << '\n';
    cout << "sizeof(int*) == " << sizeof(int*) << '\n';
    cout << "sizeof(double*) == " << sizeof(double*) << '\n';

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int, 2> d(10, 10);
    Matrix<int, 3> e(10, 10, 10);
    cout << "Matrix<int> a(10); sizeof(a) == " << sizeof(a) << ", a.size() == " << a.size() << '\n';
    cout << "Matrix<int> b(100); sizeof(b) == " << sizeof(b) << ", b.size() == " << b.size() << '\n';
    cout << "Matrix<double> c(10); sizeof(c) == " << sizeof(c) << ", c.size() == " << c.size() << '\n';
    cout << "Matrix<int, 2> d(10, 10); sizeof(d) == " << sizeof(d) << ", d.size() == " << d.size() << '\n';
    cout << "Matrix<int, 3> e(10, 10, 10); sizeof(e) == " << sizeof(e) << ", e.size() == " << e.size() << '\n';
    return 0;
}
