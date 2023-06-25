#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
struct S {
    explicit S(const T& v) :val(v) {}
    T& get();
    const T& get() const { return val; }
    S& operator=(const T& v) { val = v; }

private:
    T val;
};

template<class T>
T& S<T>::get() {
    return val;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const T& x : v)
        os << x << ' ';
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const S<T>& s) {
    return os << s.get();
}

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (T x; cin >> x;)
        v.push_back(x);
    is.clear();
    return is;
}

template<class T>
void read_val(T& v) {
    cin >> v;
}

int main() {
    S<int> si(42);
    S<char> sc('a');
    S<double> sd(3.14);
    S<string> ss("abc");
    S<vector<int>> svi({1, 2, 3, 4, 5});
    cout << "si == " << si << endl
            << "sc == " << sc << endl
            << "sd == " << sd << endl
            << "ss == " << ss << endl
            << "svi == " << svi << endl;

    read_val(si.get());
    read_val(sc.get());
    read_val(sd.get());
    read_val(ss.get());
    svi.get().clear();
    read_val(svi.get());
    cout << "si == " << si << endl
            << "sc == " << sc << endl
            << "sd == " << sd << endl
            << "ss == " << ss << endl
            << "svi == " << svi << endl;
    return 0;
}
