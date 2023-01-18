#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

// merge two files containing sorted whitespace-separated words, preserving order
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

    istream_iterator<string> iit1(ifs1), iit2(ifs2), eos;
    ostream_iterator<string> oit(ofs, "\n");
    merge(iit1, eos, iit2, eos, oit);
    return 0;
}
