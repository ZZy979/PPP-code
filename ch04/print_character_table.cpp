#include <iostream>

using namespace std;

// print a table of characters with their corresponding integer values (ASCII)
int main() {
    int i = 0;
    while (i < 26) {
        cout << char('a' + i) << '\t' << ('a' + i) << '\n';
        ++i;
    }
    return 0;
}
