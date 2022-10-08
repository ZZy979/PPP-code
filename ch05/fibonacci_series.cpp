#include <iostream>

using namespace std;

// print the first so many values of the Fibonacci series
int main() {
    int a = 1, b = 1;
    while (a > 0) {
        cout << a << endl;
        int c = a + b;
        a = b;
        b = c;
    }
    return 0;
}
