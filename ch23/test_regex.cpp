#include <iostream>
#include <regex>
#include <string>

using namespace std;

// accept a pattern and a set of lines from input
// check the pattern and search for lines with that pattern
int main() {
    regex pattern;

    string input;
    cout << "enter pattern: ";
    getline(cin, input);    // read pattern

    try {
        pattern = input;    // this checks input
        cout << "pattern: " << input << '\n';
    }
    catch (regex_error) {
        cout << input << " is not a valid regular expression\n";
        return 1;
    }

    cout << "now enter lines:\n";
    int lineno = 0;

    for (string line; getline(cin, line);) {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pattern)) {
            cout << "line " << lineno << ": " << line << '\n';
            for (int i = 0; i < matches.size(); ++i)
                cout << "\tmatches[" << i << "]: " << matches[i] << '\n';
        }
        else
            cout << "didn't match\n";
    }
    return 0;
}
