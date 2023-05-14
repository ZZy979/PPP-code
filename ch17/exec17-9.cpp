#include <iostream>

using namespace std;

int main() {
    int a = 1;
    int b = 2;
    cout << "stack grows " << (&b > &a ? "up" : "down") << endl;

    int* p = new int(3);
    int* q = new int(4);
    cout << "free store grows " << (q > p ? "up" : "down") << endl;
    delete p;
    delete q;
    return 0;
}
