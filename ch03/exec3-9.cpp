#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Please enter a number word\n";
    cin >> s;
    if (s == "zero")
        cout << 0;
    else if (s == "one")
        cout << 1;
    else if (s == "two")
        cout << 2;
    else if (s == "three")
        cout << 3;
    else if (s == "four")
        cout << 4;
    else
        cout << "not a number I know";
    cout << endl;
    return 0;
}
