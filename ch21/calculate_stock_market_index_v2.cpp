#include <iostream>
#include <map>
#include <numeric>
#include <string>

using namespace std;

// extract values and multiply
double weighted_value(const pair<string, double>& a, const pair<string, double>& b) {
    return a.second * b.second;
}

// calculate the Dow Jones Industrial index, using map
int main() {
    // Dow Jones Industrial index (symbol,price);
    // for up-to-date quotes see www.djindexes.com
    map<string, double> dow_price = {
        {"MMM", 81.86},
        {"AA", 34.69},
        {"MO", 54.45}
    };

    // Dow (symbol,weight)
    map<string, double> dow_weight = {
        {"MMM", 5.8549},
        {"AA", 2.4808},
        {"MO", 3.8940}
    };

    // Dow (symbol,name)
    map<string, string> dow_name = {
        {"MMM", "3M Co."},
        {"AA", "Alcoa Inc."},
        {"MO", "Altria Group Inc."}
    };

    // write price for each company in the Dow index:
    for (const auto& p : dow_price) {
        const string& symbol = p.first;     // the "ticker" symbol
        cout << symbol << '\t' << p.second << '\t' << dow_name[symbol] << '\n';
    }

    double dji_index = inner_product(
            dow_price.begin(), dow_price.end(), // all companies
            dow_weight.begin(), // their weights
            0.0,                // initial value
            plus<double>(),     // add (as usual)
            weighted_value);    // extract values and weights and multiply
    cout << "DJI value " << dji_index << '\n';
    return 0;
}
