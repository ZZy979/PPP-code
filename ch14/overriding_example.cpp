#include <iostream>

using namespace std;

struct B {
    virtual void f() const { cout << "B::f()" << endl; }
    void g() const { cout << "B::g()" << endl; }    // not virtual
};

struct D : B {
    void f() const { cout << "D::f()" << endl; }    // overrides B::f()
    void g() { cout << "D::g()" << endl; }
};

struct DD : D {
    void f() { cout << "DD::f()" << endl; }         // doesn't override D::f() (not const)
    void g() const { cout << "DD:g()" << endl; }    // hides B::g()
};

// a D is a kind of B, so call() can accept a D
// a DD is a kind of D and a D is a kind of B, so call() can accept a DD
void call(const B& b) {
    b.f();
    b.g();
}

// a purely technical example that illustrates overriding
int main() {
    B b;
    D d;
    DD dd;

    call(b);
    call(d);
    call(dd);

    b.f();
    b.g();

    d.f();
    d.g();

    dd.f();
    dd.g();
    return 0;
}
