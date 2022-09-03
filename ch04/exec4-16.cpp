#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find min, max and mode in a sequence of numbers
int main() {
    vector<int> v;
    int x;
    while (cin >> x)
        v.push_back(x);
    if (v.empty()) {
        cout << "empty sequence\n";
        return 0;
    }
    sort(v.begin(), v.end());

    int count = 1, mode_count = 1, mode = v[0];
    for (int i = 1; i < v.size(); ++i)
        if (v[i] != v[i - 1]) {
            if (count > mode_count) {
                mode = v[i - 1];
                mode_count = count;
                count = 1;
            }
        }
        else
            ++count;
    cout << "min=" << v[0] << endl
            << "max=" << v[v.size() - 1] << endl
            << "mode=" << mode << endl;
    return 0;
}
