#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> temps;   // temperatures
    double temp = 0;

    while (cin >> temp)     // read and put into temps
        temps.push_back(temp);

    double sum = 0;
    double high_temp = 0;
    double low_temp = 0;

    for (double x : temps) {
        if (x > high_temp) high_temp = x;   // find high
        if (x < low_temp) low_temp = x;     // find low
        sum += x;                           // compute sum
    }

    cout << "High temperature: " << high_temp << endl;
    cout << "Low temperature: " << low_temp << endl;
    cout << "Average temperature: " << sum / temps.size() << endl;
    return 0;
}
