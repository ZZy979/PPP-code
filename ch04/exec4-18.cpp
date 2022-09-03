#include <cmath>
#include <iostream>

using namespace std;

// solve quadratic equation
int main() {
    double a, b, c;
    cout << "Please enter the coefficients a,b,c:\n";
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    double p = -b / (2 * a), q = fabs(sqrt(fabs(delta)) / (2 * a));
    if (delta >= 0)
        cout << "x1=" << p - q << ", x2=" << p + q << endl;
    else
        cout << "x1=" << p << '-' << q << "i, x2=" << p << '+' << q << "i" << endl;
    return 0;
}
