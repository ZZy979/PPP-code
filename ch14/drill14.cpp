#include <iostream>
#include <string>

using namespace std;

class B1 {
public:
    void f() { cout << "B1::f()" << endl; }
    virtual void vf() { cout << "B1::vf()" << endl; }
    virtual void pvf() = 0;
};

class D1 : public B1 {
public:
    void vf() override { cout << "D1::vf()" << endl; }
    void pvf() override { cout << "D1::pvf()" << endl; }
};

class D12 : public B1 {
public:
    void f() { cout << "D12::f()" << endl; }
    void vf() override { cout << "D12::vf()" << endl; }
    void pvf() override { cout << "D12::pvf()" << endl; }
};

class D2 : public D12 {
public:
    void pvf() override { cout << "D2::pvf()" << endl; }
};

void f(B1& b1) {
    b1.f();
    b1.vf();
    b1.pvf();
}

class B2 {
public:
    virtual void pvf() = 0;
};

class D21 : public B2 {
public:
    D21(const string& s) :s(s) {}
    void pvf() override { cout << s << endl; }

    string s;
};

class D22 : public B2 {
public:
    D22(int i) :i(i) {}
    void pvf() override { cout << i << endl; }

    int i;
};

void f(B2& b2) {
    b2.pvf();
}

int main() {
    D1 d1;
    d1.f();
    d1.vf();
    d1.pvf();

    D12 d12;
    d12.f();
    d12.vf();
    d12.pvf();

    f(d1);
    f(d12);

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    D21 d21("abc");
    D22 d22(123);
    f(d21);
    f(d22);
    return 0;
}
