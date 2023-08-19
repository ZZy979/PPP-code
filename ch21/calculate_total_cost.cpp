#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Item {
    double unit_price;
    int units;  // number of units sold
};

// calculate the total cost of items given the unit prices and number of units
int main() {
    vector<Item> v;
    for (Item item; cin >> item.unit_price >> item.units;)
        v.push_back(item);

    auto add_price = [](double p, const Item& i) { return p + i.unit_price * i.units; };
    double total = accumulate(v.begin(), v.end(), 0.0, add_price);
    cout << "Total cost of items: " << fixed << setprecision(2) << total << endl;
    return 0;
}
