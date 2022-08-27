#include <iostream>

using namespace std;

// print a table of characters and digits with their corresponding integer values (ASCII)
int main() {
    for (int i = 0; i < 26; ++i)
        cout << char('a' + i) << '\t' << ('a' + i) << '\n';
    for (int i = 0; i < 26; ++i)
        cout << char('A' + i) << '\t' << ('A' + i) << '\n';
    for (int i = 0; i < 10; ++i)
        cout << char('0' + i) << '\t' << ('0' + i) << '\n';
    return 0;
}
