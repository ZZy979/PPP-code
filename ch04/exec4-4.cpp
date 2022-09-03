#include <iostream>

using namespace std;

// numbers guessing game
int main() {
    int lower = 1, upper = 100, x;
    while (lower < upper) {
        x = (upper + lower) / 2;
        cout << "Is the number you are thinking of greater than " << x << "? (y/n)" << endl;
        char c;
        cin >> c;
        if (c == 'y')
            lower = x + 1;
        else if (c == 'n')
            upper = x;
        else
            cout << "Please enter y/n" << endl;
    }
    cout << "The number you are thinking is " << lower << endl;
    return 0;
}
