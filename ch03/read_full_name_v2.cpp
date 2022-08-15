#include <iostream>
#include <string>

using namespace std;

// read first and second name
int main() {
    cout << "Please enter your first and second names\n";
    string first;
    string second;
    cin >> first >> second;                 // read two strings
    string name = first + ' ' + second;     // concatenate strings
    cout << "Hello, " << name << '\n';
    return 0;
}
