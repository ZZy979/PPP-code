#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// compute mean and median temperatures
int main() {
    vector<double> temps;       // temperatures
    double temp;
    while (cin >> temp)         // read
        temps.push_back(temp);  // put into vector

    // compute mean temperature:
    double sum = 0;
    for (int i = 0; i < temps.size(); ++i)
        sum += temps[i];
    cout << "Average temperature: " << sum / temps.size() << endl;

    // compute median temperature:
    double median;
    sort(temps.begin(), temps.end());   // sort temps
    if (temps.size() % 2 == 1)
        median = temps[temps.size() / 2];
    else
        median = (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2;
    cout << "Median temperature: " << median << endl;
    return 0;
}
