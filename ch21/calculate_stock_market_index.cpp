#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

using namespace std;

// calculate the Dow Jones Industrial index
int main() {
    vector<double> dow_price;   // share price for each company
    list<double> dow_weight;    // weight in index for each company
    for (double p, w; cin >> p >> w;) {
        dow_price.push_back(p);
        dow_weight.push_back(w);
    }

    // multiply (weight,value) pairs and add
    double dji_index = inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0);

    cout << "DJI value " << fixed << setprecision(6) << dji_index << '\n';
    return 0;
}
