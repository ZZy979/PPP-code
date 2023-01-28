#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void convert(const string& s);

// Read octal, decimal, or hexadecimal integers and convert them to decimal form.
int main() {
    string s;
    while (cin >> s)
        convert(s);
    return 0;
}

void convert(const string& s) {
    try {
        string radix;
        int n = 0;
        if (s.length() >= 3 && s[0] == '0' && s[1] == 'x') {
            radix = "hexadecimal";
            n = stoi(s, nullptr, 16);
        }
        else if (s.length() >= 2 && s[0] == '0') {
            radix = "octal";
            n = stoi(s, nullptr, 8);
        }
        else {
            radix = "decimal";
            n = stoi(s, nullptr, 10);
        }
        cout << setw(15) << s << setw(12) << radix
                << " converts to " << setw(15) << n << " decimal" << endl;
    }
    catch (invalid_argument&) {
        cout << s << " is not an integer" << endl;
    }
}
