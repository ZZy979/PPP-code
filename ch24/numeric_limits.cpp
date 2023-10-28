#include <climits>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "number of bytes in an int: " << sizeof(int) << '\n';
    cout << "largest int: " << INT_MAX << '\n';
    cout << "smallest int value: " << numeric_limits<int>::min() << '\n';

    if (numeric_limits<char>::is_signed)
        cout << "char is signed\n";
    else
        cout << "char is unsigned\n";

    char ch = numeric_limits<char>::min();  // smallest positive value
    cout << "the char with the smallest positive value: " << ch << '\n';
    cout << "the int value of the char with the smallest positive value: "
            << int(ch) << '\n';
    return 0;
}
