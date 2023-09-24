#include <iostream>
#include <map>
#include <numeric>
#include <string>

using namespace std;

template<class K, class V>
void print_map(const map<K, V>& m) {
    for (const auto& p : m)
        cout << '(' << p.first << ',' << p.second << ')' << endl;
}

template<class K, class V>
void read_pairs(map<K, V>& m) {
    for (pair<K, V> p; cin >> p.first >> p.second;)
        m.insert(p);
}

int main() {
    map<string, int> msi = {
        {"apple", 5},
        {"banana", 7},
        {"car", 30000},
        {"dog", 15},
        {"education", 12},
        {"football", 10},
        {"guitar", 500},
        {"house", 500000},
        {"internet", 20},
        {"jacket", 50}
    };
    cout << "(name, value) pairs in msi:\n";
    print_map(msi);

    msi.erase("car");
    msi.erase("guitar");
    cout << "\nErase pairs:\n";
    print_map(msi);

    read_pairs(msi);
    cout << "\nRead pairs from input:\n";
    print_map(msi);

    int sum = accumulate(msi.begin(), msi.end(), 0, [](int x, const pair<string, int>& p) { return x + p.second; });
    cout << "\nSum of the values in msi is " << sum << endl;

    map<int, string> mis;
    for (const auto& p : msi)
        mis.emplace(p.second, p.first);
    cout << "\n(value, name) pairs in mis:\n";
    print_map(mis);
    return 0;
}
