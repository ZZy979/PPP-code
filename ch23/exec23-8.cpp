#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

// Take as inputs a pattern and a file name, output numbered lines that contain a match of the pattern.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " pattern filename\n";
        return 0;
    }

    regex pattern;
    try {
        pattern = argv[1];
    }
    catch (regex_error& e) {
        cerr << "invalid regular expression: " << argv[1] << '\n';
        return 1;
    }

    ifstream ifs(argv[2]);
    if (!ifs) {
        cerr << "can't open input file " << argv[2] << endl;
        return 1;
    }

    string line;
    for (int lineno = 1; getline(ifs, line); ++lineno)
        if (regex_search(line, pattern))
            cout << lineno << ": " << line << '\n';
    return 0;
}
