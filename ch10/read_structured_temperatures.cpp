#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "temperature_reading.h"

using namespace std;

// read structured temperature readings from file
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " input_file output_file\n";
        return 0;
    }

    try {
        // open an input file:
        string iname = argv[1];
        ifstream ifs(iname);
        if (!ifs)
            throw runtime_error("can't open input file: " + iname);
        ifs.exceptions(ios_base::badbit);   // throw for bad()

        // open an output file:
        string oname = argv[2];
        ofstream ofs(oname);
        if (!ofs)
            throw runtime_error("can't open output file: " + oname);

        // read an arbitrary number of years:
        vector<Year> ys;
        while (true) {
            Year y;     // get a freshly initialized Year each time around
            if (!(ifs >> y)) break;
            ys.push_back(y);
        }
        cout << "read " << ys.size() << " years of readings\n";

        for (const Year& y: ys)
            ofs << y << endl;
        return 0;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
