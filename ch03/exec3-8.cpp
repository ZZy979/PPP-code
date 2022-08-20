#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Please enter an integer\n";
    cin >> n;
    if (n % 2 == 1)
        cout << "The value " << n << " is an odd number." << endl;
    else
        cout << "The value " << n << " is an even number." << endl;
    return 0;
}
