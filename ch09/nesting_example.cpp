// struct
struct X {
    // member function
    void f(int x) {
        // local struct
        struct Y {
            // member function
            int f() { return 1; }

            int m;
        };
        int m;
        m = x;
        Y m2;
        return f(m2.f());
    }

    int m;

    // member function
    void g(int m) {
        if (m) f(m + 2);
        else {
            g(m + 2);
        }
    }

    // constructor
    X() {}

    // member function
    void m3() {
    }

    // member function
    void main() {
        X a;
        a.f(2);
    }
};
