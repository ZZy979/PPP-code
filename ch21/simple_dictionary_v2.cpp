#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

// "quick and dirty" dictionary: read words from a text file, sort and remove duplicates,
// then write to another file
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " input_file output_file\n";
        return 0;
    }

    ifstream is(argv[1]);   // open input stream
    ofstream os(argv[2]);   // open output stream

    istream_iterator<string> ii(is);        // make input iterator for stream
    istream_iterator<string> eos;           // input sentinel
    ostream_iterator<string> oo(os, "\n");  // make output iterator for stream

    vector<string> b(ii, eos);              // b is a vector initialized from input
    sort(b.begin(), b.end());               // sort the buffer
    unique_copy(b.begin(), b.end(), oo);    // copy buffer to output
    return 0;
}
