#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int i = 12345;
    double d = 1234.5;
    string s = "abcde";
    cout << i <<'|'<< setw(4) << i << '|' << setw(8) << i << '|' << i << "|\n";
    cout << d <<'|'<< setw(4) << d << '|' << setw(8) << d << '|' << d << "|\n";
    cout << s <<'|'<< setw(4) << s << '|' << setw(8) << s << '|' << s << "|\n";
    return 0;
}
