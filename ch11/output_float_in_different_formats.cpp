#include <iostream>

using namespace std;

// Print floating-point value using defaultfloat, fixed and scientific format.
int main() {
    cout << 1234567.89 << "    (defaultfloat)\n"
            << fixed << 1234567.89 << " (fixed)\n"
            << scientific << 1234567.89 << "   (scientific)\n";
    return 0;
}
