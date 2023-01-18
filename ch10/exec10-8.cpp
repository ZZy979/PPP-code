#include <fstream>
#include <iostream>

using namespace std;

void copy(istream& is, ostream& os);

// concatenate two files
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " input_file1 input_file2 output_file\n";
        return 0;
    }

    ifstream ifs1(argv[1]);
    if (!ifs1) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    ifstream ifs2(argv[2]);
    if (!ifs2) {
        cerr << "can't open input file " << argv[2] << endl;
        return 1;
    }

    ofstream ofs(argv[3]);
    if (!ofs) {
        cerr << "can't open output file " << argv[3] << endl;
        return 1;
    }

    copy(ifs1, ofs);
    copy(ifs2, ofs);
    return 0;
}

void copy(istream& is, ostream& os) {
    char c;
    while (is.get(c))
        os << c;
}
