#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int a[], int n) {
    int la[10];
    copy(ga, ga + 10, la);
    for (int x : la)
        cout << x << ' ';
    cout << endl;

    int* p = new int[n];
    copy(a, a + n, p);
    for (int i = 0; i < n; ++i)
        cout << p[i] << ' ';
    cout << endl;
    delete[] p;
}

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const vector<int>& v) {
    vector<int> lv(gv.size());
    lv = gv;
    for (int x : lv)
        cout << x << ' ';
    cout << endl;

    vector<int> lv2 = v;
    for (int x : lv2)
        cout << x << ' ';
    cout << endl;
}

int main() {
    // array drill
    f(ga, 10);
    int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    f(aa, 10);

    // vector drill
    f(gv);
    vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    f(vv);
    return 0;
}
