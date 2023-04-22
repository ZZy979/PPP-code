#include <iostream>

using namespace std;

class C {
public:
    C() { cout << "C::C()\n"; }
    ~C() { cout << "C::~C()\n"; }
};

class B {
public:
    B() { cout << "B::B()\n"; }
    virtual ~B() { cout << "B::~B()\n"; }
};

class D : public B {
public:
    D() { cout << "D::D()\n"; }
    ~D() { cout << "D::~D()\n"; }

private:
    C c;
};

int main() {
    B* b = new D;
    delete b;
    return 0;
}
