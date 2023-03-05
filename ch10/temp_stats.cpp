#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

#include "ch05/temperature_converters.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " filename\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    vector<double> temps;
    int h;
    double t;
    char u;
    while (ifs >> h >> t >> u)
        temps.push_back(u == 'f' ? ftoc(t) : t);

    double sum = accumulate(temps.begin(), temps.end(), 0.0);
    cout << "mean temps: " << sum / temps.size() << endl;

    sort(temps.begin(), temps.end());
    double median = temps.size() % 2 == 1 ? temps[temps.size() / 2] :
            (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2;
    cout << "median temps: " << median << endl;
    return 0;
}
