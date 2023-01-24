#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

char* as_bytes(int& i);

// Read and write binary file of integers.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " input_file output_file\n";
        return 0;
    }

    // open an istream for binary input from a file:
    // note: stream mode binary tells the stream not to try anything clever with the bytes
    ifstream ifs(argv[1], ios_base::binary);
    if (!ifs) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    // open an ostream for binary output to a file:
    ofstream ofs(argv[2], ios_base::binary);
    if (!ofs) {
        cerr << "can't open output file " << argv[2] << endl;
        return 1;
    }

    vector<int> v;

    // read from binary file:
    for (int x; ifs.read(as_bytes(x), sizeof(int));) // note: reading bytes
        v.push_back(x);

    // ... do something with v ...

    // write to binary file:
    for (int x : v)
        ofs.write(as_bytes(x), sizeof(int));    // note: writing bytes
    return 0;
}

char* as_bytes(int& i) {
    return reinterpret_cast<char*>(&i);
}
