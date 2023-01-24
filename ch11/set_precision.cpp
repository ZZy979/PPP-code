#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double d = 1234.56789;
    cout << d << '\t'
            << fixed << d << '\t'
            << scientific << d << '\n';
    cout << setprecision(5)
            << defaultfloat << d << '\t'
            << fixed << d << '\t'
            << scientific << d << '\n';
    cout << setprecision(8)
            << defaultfloat << d << '\t'
            << fixed << d << '\t'
            << scientific << d << '\n';
    return 0;
}
