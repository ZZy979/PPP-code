#include <iostream>
#include <string>

using namespace std;

// Reverse the order of characters from input.
int main() {
    string s;
    char c;
    while (cin.get(c))
        s += c;

    for (int i = s.length() - 1; i >= 0; --i)
        cout << s[i];
    return 0;
}
