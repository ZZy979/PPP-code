#include <iostream>

using namespace std;

// Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D Matrix.
// Take n and m from cin and print out the table nicely.
int main() {
    int n;
    cin >> n;

    // Why use Matrix?
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            cout << j << '*' << i << '=' << i * j << '\t';
        cout << '\n';
    }
    return 0;
}
