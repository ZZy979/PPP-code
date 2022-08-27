#include <iostream>

using namespace std;

// return the square of x
int square(int x) {
    return x * x;
}

// calculate and print a table of squares 0–99
int main() {
    for (int i = 0; i < 100; ++i)
        cout << i << '\t' << square(i) << '\n';
    return 0;
}
