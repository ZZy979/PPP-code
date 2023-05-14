#include <iostream>

using namespace std;

int main() {
    int a[2];
    cout << "sizeof int is " << (reinterpret_cast<intptr_t>(&a[1]) - reinterpret_cast<intptr_t>(&a[0])) << endl;

    double b[2];
    cout << "sizeof double is " << (reinterpret_cast<intptr_t>(&b[1]) - reinterpret_cast<intptr_t>(&b[0])) << endl;

    bool c[2];
    cout << "sizeof bool is " << (reinterpret_cast<intptr_t>(&c[1]) - reinterpret_cast<intptr_t>(&c[0])) << endl;
    return 0;
}
