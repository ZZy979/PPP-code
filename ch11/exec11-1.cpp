#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

// Read a text file, convert all letters to lowercase and produce a new file.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " input_file output_file\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    ofstream ofs(argv[2]);
    if (!ofs) {
        cerr << "can't open output file " << argv[2] << endl;
        return 1;
    }

    char c;
    while (ifs.get(c))
        ofs << char(tolower(c));
    return 0;
}
