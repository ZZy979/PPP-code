#include <complex>
#include <iostream>
#include <valarray>

using namespace std;

// Read ten complex<double>s from cin and put them into a Matrix.
// Calculate and output the sum of the ten complex numbers.
int main() {
    // Without Matrix::sum(), why use Matrix?
    valarray<complex<double>> v(10);
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
    cout << v.sum() << '\n';
    return 0;
}
