#include <iostream>
#include <string>
#include <vector>

using namespace std;

// simple test class
struct X {
    int val;

    void out(const string& s, int nv) {
        cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    X() { out("X()", 0); val = 0; }     // default constructor
    X(int v) { val = v; out("X(int)", v); }
    X(const X& x) { val = x.val; out("X(X&)", x.val); }     // copy constructor
    X& operator=(const X& x)    // copy assignment
            { out("X::operator=(X&)", x.val); val = x.val; return *this; }
    ~X() { out("~X()", 0); }    // destructor
};

X glob(2);      // a global variable

X copy(X x) { return x; }

X copy2(X x) { X xx = x; return xx; }

X& ref_to(X& x) { return x; }

X* make(int v) { X x(v); return new X(v); }

struct XX { X a; X b; };

int main() {
    X loc(4);       // local variable
    X loc2(loc);    // copy construction
    loc = X(5);     // copy assignment
    loc2 = copy(loc);       // call by value and return
    loc2 = copy2(loc);
    X loc3(6);
    X& r = ref_to(loc);     // call by reference and return
    delete make(7);
    delete make(8);
    vector<X> v(4);         // default values
    XX loc4;
    X* p = new X(9);        // an X on the free store
    delete p;
    X* pp = new X[5];       // an array of Xs on the free store
    delete[] pp;
    return 0;
}
