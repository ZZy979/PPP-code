#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "../ch05/temperature_converters.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " filename N_readings\n";
        return 0;
    }

    ofstream ofs(argv[1]);
    if (!ofs) {
        cerr << "can't open output file " << argv[1] << endl;
        return 1;
    }

    int n = stoi(argv[2]);
    mt19937 generator;
    uniform_real_distribution<double> temperature_dist(-10, 30);
    bernoulli_distribution unit_dist(0.5);
    for (int i = 0; i < n; ++i) {
        int hour = i % 24;
        double celsius = temperature_dist(generator);
        if (unit_dist(generator))
            ofs << hour << ' ' << celsius << " c" << endl;
        else
            ofs << hour << ' ' << ctof(celsius) << " f" << endl;
    }
    return 0;
}
