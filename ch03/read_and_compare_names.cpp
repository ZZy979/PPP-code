#include <iostream>
#include <string>

using namespace std;

// read and compare names
int main() {
    cout << "Please enter two names\n";
    string first;
    string second;
    cin >> first >> second;     // read two strings
    if (first == second)
        cout << "that's the same name twice\n";
    if (first < second)
        cout << first << " is alphabetically before " << second << '\n';
    if (first > second)
        cout << first << " is alphabetically after " << second << '\n';
    return 0;
}
