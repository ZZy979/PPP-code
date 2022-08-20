#include <iostream>

using namespace std;

int main() {
    string operation;
    double a = 0.0, b = 0.0;
    cin >> operation >> a >> b;
    if (operation == "+")
        cout << a + b;
    else if (operation == "-")
        cout << a - b;
    else if (operation == "*")
        cout << a * b;
    else if (operation == "/") {
        if (b == 0)
            cout << "error: divided by zero";
        else
            cout << a / b;
    }
    cout << endl;
    return 0;
}
