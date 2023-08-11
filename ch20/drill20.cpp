#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "copy.h"

using namespace std;

template<class Iter>
void print(const std::string& name, Iter first, Iter last) {
    cout << name << " = { ";
    for (; first != last; ++first)
        cout << *first << ", ";
    cout << "}\n";
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int a2[10];
    my_copy(a, a + 10, a2);
    vector<int> v2 = v;
    list<int> l2 = l;
    print("a2", a2, a2 + 10);
    print("v2", v2.begin(), v2.end());
    print("l2", l2.begin(), l2.end());
    cout << endl;

    for (int& x : a) x += 2;
    for (int& x : v) x += 3;
    for (int& x : l) x += 5;
    print("a", a, a + 10);
    print("v", v.begin(), v.end());
    print("l", l.begin(), l.end());
    cout << endl;

    my_copy(a, a + 10, v.begin());
    my_copy(l.begin(), l.end(), a);
    print("a", a, a + 10);
    print("v", v.begin(), v.end());
    print("l", l.begin(), l.end());
    cout << endl;

    auto it = std::find(v.begin(), v.end(), 3);
    if (it == v.end())
        cout << "v doesn't contain value 3\n";
    else
        cout << "v contains value 3 at position " << it - v.begin() << '\n';

    auto it2 = std::find(l.begin(), l.end(), 27);
    if (it2 == l.end())
        cout << "l doesn't contain value 27\n";
    else
        cout << "l contains value 27\n";
    return 0;
}
