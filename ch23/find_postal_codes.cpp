#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

// Find postal codes in a file.
// If the program finds an occurrence of the pattern in a line, it writes out the line number and what it found.
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " filename\n";
        return 0;
    }

    ifstream in(argv[1]);
    if (!in) {
        cerr << "no file\n";
        return 1;
    }

    regex pat(R"(\w{2}\s*\d{5}(-\d{4})?)");     // postal code pattern

    int lineno = 0;
    for (string line; getline(in, line);) {     // read input line into input buffer
        ++lineno;
        smatch matches;     // matched strings go here
        if (regex_search(line, matches, pat)) {
            cout << lineno << ": " << matches[0] << '\n';   // whole match
            if (matches.size() > 1 && matches[1].matched)
                cout << "\t: " << matches[1] << '\n';       // sub-match
        }
    }
    return 0;
}
