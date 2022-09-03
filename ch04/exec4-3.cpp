#include <cfloat>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> distances;
    double d, sum = 0, min = DBL_MAX, max = -DBL_MAX;
    while (cin >> d) {
        distances.push_back(d);
        sum += d;
        if (d < min)
            min = d;
        if (d > max)
            max = d;
    }
    cout << "sum=" << sum << endl
            << "min=" << min << endl
            << "max=" << max << endl
            << "mean=" << sum / distances.size() << endl;
    return 0;
}
