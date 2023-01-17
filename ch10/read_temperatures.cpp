#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// a temperature reading
struct Reading {
    int hour;               // hour after midnight [0:23]
    double temperature;     // in Fahrenheit
};

// read temperature readings (hour,temperature) from data file and print them out
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " input_file output_file\n";
        return 0;
    }

    try {
        string iname = argv[1];
        ifstream ifs(iname);    // ifs reads from the file named iname
        if (!ifs)
            throw runtime_error("can't open input file " + iname);

        string oname = argv[2];
        ofstream ofs(oname);    // ofs writes to a file named oname
        if (!ofs)
            throw runtime_error("can't open output file " + oname);

        vector<Reading> temps;  // store the readings here
        int hour;
        double temperature;
        while (ifs >> hour >> temperature) {
            if (hour < 0 || hour > 23)
                throw runtime_error("hour out of range");
            temps.push_back({hour, temperature});
        }

        for (const Reading& r : temps)
            ofs << '(' << r.hour << ',' << r.temperature << ")\n";
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
