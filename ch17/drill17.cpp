#include <iostream>
#include <vector>

using namespace std;

ostream& print_array10(ostream& os, int* a);
ostream& print_array(ostream& os, int* a, int n);
ostream& print_vector(ostream& os, const vector<int>& v);

int main() {
    // Part 1
    int* a1 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; ++i)
        cout << a1[i] << ' ';
    cout << endl;
    delete[] a1;

    int* a2 = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    int* a3 = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_array10(cout, a2) << endl;
    print_array10(cout, a3) << a3[10] << endl;
    delete[] a2;
    delete[] a3;

    int* a4 = new int[20]{
        100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
        110, 111, 112, 113, 114, 115, 116, 117, 118, 119
    };
    print_array(cout, a4, 20) << endl;
    delete[] a4;

    vector<int> v2 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    vector<int> v3 = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    vector<int> v4 = {
        100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
        110, 111, 112, 113, 114, 115, 116, 117, 118, 119
    };
    print_vector(cout, v2) << endl;
    print_vector(cout, v3) << endl;
    print_vector(cout, v4) << endl;

    // Part 2
    int* p1 = new int(7);
    cout << p1 << ' ' << *p1 << endl;

    int* p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
    cout << p2 << ' ';
    print_array(cout, p2, 7) << endl;

    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    cout << p1 << ' ';
    print_array(cout, p1, 1) << endl;
    cout << p2 << ' ';
    print_array(cout, p2, 7) << endl;
    delete p1;
    delete[] p2;

    int* a5 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int* a6 = new int[10];
    for (int i = 0; i < 10; ++i)
        a6[i] = a5[i];
    print_array(cout, a6, 10) << endl;
    delete[] a5;
    delete[] a6;

    vector<int> v5 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> v6 = v5;
    print_vector(cout, v6) << endl;
    return 0;
}

ostream& print_array10(ostream& os, int* a) {
    for (int i = 0; i < 10; ++i)
        os << a[i] << ' ';
    return os;
}

ostream& print_array(ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i)
        os << a[i] << ' ';
    return os;
}

ostream& print_vector(ostream& os, const vector<int>& v) {
    for (int x : v)
        os << x << ' ';
    return os;
}
