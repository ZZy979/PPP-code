#include <iostream>

using namespace std;

int main() {
    int val1 = 0, val2 = 0;
    cout << "Please enter two integers\n";
    cin >> val1 >> val2;
    if (val1 < val2)
        cout << "min = " << val1 << "\nmax = " << val2 << endl;
    else
        cout << "min = " << val2 << "\nmax = " << val1 << endl;
    cout << "val1 + val2 = " << (val1 + val2) << endl;
    cout << "val1 - val2 = " << (val1 - val2) << endl;
    cout << "val1 * val2 = " << (val1 * val2) << endl;
    if (val2 == 0)
        cout << "error: divided by zero" << endl;
    else
        cout << "val1 / val2 = " << (val1 / val2) << endl;
    return 0;
}
