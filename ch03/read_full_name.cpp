#include <iostream>
#include <string>

using namespace std;

// read full name
int main() {
    cout << "Please enter your first and second names\n";
    string first;
    string second;
    cin >> first >> second;     // read two strings
    cout << "Hello, " << first << ' ' << second << '\n';
    return 0;
}
