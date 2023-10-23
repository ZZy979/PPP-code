#include <iostream>
#include <regex>

using namespace std;

int main() {
    if (regex_match("\n", regex(".")))
        cout << ". matches '\\n'\n";
    else
        cout << ". doesn't match '\\n'\n";
    return 0;
}
