#include <iostream>
#include <cmath>

using namespace std;

// simple program to exercise operators
int main() {
    cout << "Please enter an integer value:\n";
    int n;
    cin >> n;
    cout << "n == " << n
            << "\nn+1 == " << n + 1
            << "\nthree times n == " << 3 * n
            << "\ntwice n == " << n + n
            << "\nn squared == " << n * n
            << "\nhalf of n == " << n / 2
            << "\nn % 2 == " << n % 2
            << "\nn / 3 * 3 + n % 3 == " << n / 3 * 3 + n % 3
            << "\nsquare root of n == " << sqrt(n)
            << endl;    // another name for newline ("end of line")
    return 0;
}
