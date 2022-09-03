#include <iostream>

using namespace std;

// very simple calculator
int main() {
    double x = 0, y = 0;
    char op;
    cout << "Please enter two floating-point numbers and an operator (+ - * /)\n";
    cin >> x >> y >> op;
    switch (op) {
        case '+':
            cout << "The sum of " << x << " and " << y << " is " << x + y << endl;
            break;
        case '-':
            cout << "The difference between " << x << " and " << y << " is " << x - y << endl;
            break;
        case '*':
            cout << "The product of " << x << " and " << y << " is " << x * y << endl;
            break;
        case '/':
            if (y == 0)
                cout << "error: divided by 0\n";
            else
                cout << "The quotient of " << x << " and " << y << " is " << x / y << endl;
            break;
        default:
            cout << "error: invalid operator " << op << endl;
    }
    return 0;
}
