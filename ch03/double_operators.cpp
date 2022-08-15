#include <iostream>
#include <cmath>

using namespace std;

// simple program to exercise operators
int main() {
    cout << "Please enter a floating-point value:\n";
    double n;
    cin >> n;
    cout << "n == " << n
            << "\nn+1 == " << n + 1
            << "\nthree times n == " << 3 * n
            << "\ntwice n == " << n + n
            << "\nn squared == " << n * n
            << "\nhalf of n == " << n / 2
            << "\nsquare root of n == " << sqrt(n)
            << endl;    // another name for newline ("end of line")
    return 0;
}
