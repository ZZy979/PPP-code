#include <iostream>
#include <vector>

using namespace std;

// calculate the sum of the first n integers
int main() {
    cout << "Please enter the number of values you want to sum:\n";
    int n;
    cin >> n;

    cout << "Please enter some integers (press '|' to stop):\n";
    vector<int> v;
    int x, sum = 0;
    while (v.size() < n && cin >> x) {
        v.push_back(x);
        sum += x;
    }

    if (v.size() < n) {
        cerr << "Less than " << n << " numbers input\n";
        return 0;
    }
    cout << "The sum of the first " << n << " numbers ( ";
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
    cout << ") is " << sum << endl;
    return 0;
}
