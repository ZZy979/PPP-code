#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Given a file name and a word, output each line that contains that word together with the line number.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " filename word\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    string word = argv[2], line;
    for (int lineno = 1; getline(ifs, line); ++lineno)
        if (line.find(word) != string::npos)
            cout << lineno << ' ' << line << endl;
    return 0;
}
