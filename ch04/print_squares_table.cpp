#include <iostream>

using namespace std;

// return the square of x
int square(int x) {
    return x * x;
}

// calculate and print a table of squares 0–99
int main() {
    int i = 0;  // start from 0
    while (i < 100) {
        cout << i << '\t' << square(i) << '\n';
        ++i;
    }
    return 0;
}
