#include <climits>
#include <cstdint>
#include <iostream>

using namespace std;

// print the first so many values of the Fibonacci series
int main() {
    uint64_t a = 1, b = 1;
    while (a <= INT_MAX) {
        cout << a << endl;
        uint64_t c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
