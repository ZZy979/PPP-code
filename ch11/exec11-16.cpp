#include <iostream>
#include <map>

using namespace std;

// Read whitespace-separated numbers and output them in order (lowest value first).
// Write a value only once, and if it occurs more than once write the count of its occurrences on its line.
int main() {
    map<int, int> m;
    for (int n; cin >> n;)
        ++m[n];

    for (const auto& p : m) {
        cout << p.first;
        if (p.second > 1)
            cout << ' ' << p.second;
        cout << endl;
    }
    return 0;
}
