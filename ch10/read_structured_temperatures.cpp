#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "temperature_reading.h"

using namespace std;

// read structured temperature readings from file
int main() {
    // open an input file:
    cout << "Please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ifs(iname);
    if (!ifs)
        throw runtime_error("can't open input file: " + iname);
    ifs.exceptions(ios_base::badbit);   // throw for bad()

    // open an output file:
    cout << "Please enter output file name\n";
    string oname;
    cin >> oname;
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

    for (const Year& y : ys)
        ofs << y << endl;
    return 0;
}
