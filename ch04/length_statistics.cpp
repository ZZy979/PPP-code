#include <cfloat>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    double x, sum = 0;
    string unit;
    vector<double> lengths;
    double min = DBL_MAX, max = -DBL_MAX;
    const double ft_per_cm = 1 / (2.54 * 12), ft_per_m = 100 / (2.54 * 12), ft_per_in = 1.0 / 12;
    while (cin >> x >> unit) {
        if (unit == "cm")
            x *= ft_per_cm;
        else if (unit == "m")
            x *= ft_per_m;
        else if (unit == "in")
            x *= ft_per_in;
        else if (unit == "ft");
        else {
            cout << "invalid unit: " << unit << endl;
            continue;
        }
        cout << x << " ft";
        sum += x;
        lengths.push_back(x);
        if (x < min) {
            min = x;
            cout << " the smallest so far";
        }
        if (x > max) {
            max = x;
            cout << " the largest so far";
        }
        cout << endl;
    }
    sort(lengths.begin(), lengths.end());
    for (double d: lengths)
        cout << d << ' ';
    cout << "\nmax=" << max << " ft\n"
            << "min=" << min << " ft\n"
            << "sum=" << sum << " ft\n"
            << "count=" << lengths.size() << endl;
    return 0;
}
