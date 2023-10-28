#include <iomanip>
#include <iostream>

using namespace std;

void f(int i, double fpd) {
    char c = i;         // yes: chars really are very small integers
    short s = i;        // beware: an int may not fit in a short int
    i = i + 1;          // what if i was the largest int?
    long lg = i * i;    // beware: a long may not be any larger than an int
    float fps = fpd;    // beware: a large double may not fit in a float
    cout << "c = " << int(c) << ", s = " << s << ", i = " << i << ", lg = " << lg
            << ", fps = " << setprecision(10) << fps << '\n';

    fps = i;            // you can lose precision (for very large int values)
    i = fpd;            // truncates: e.g., 5.7 -> 5
    cout << "fps = " << setprecision(10) << fps << ", i = " << i << '\n';
}

void g() {
    char ch = 0;
    for (int i = 0; i < 256; ++i)
        cout << int(ch++) << ((i + 1) % 10 == 0 ? '\n' : '\t');
}

int main() {
    f(10000, 5.7);
    f(100000, 3e8);
    f(2100000009, 3e10);
    f(2147483647, 3e80);
    g();
    return 0;
}
