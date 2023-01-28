#include <iomanip>
#include <iostream>

using namespace std;

// Read whitespace-separated numbers and output using scientific format
// and precision 8 in four fields of 20 characters per line.
int main() {
    double d;
    cout << scientific << setprecision(8);
    for (int n = 0; cin >> d; ++n) {
        cout << setw(20) << d;
        if (n % 4 == 3)
            cout << endl;
    }
    return 0;
}
