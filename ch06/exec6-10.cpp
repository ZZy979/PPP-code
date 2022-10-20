#include <iostream>

using namespace std;

double production(int a, int b);
double permutation(int n, int m);
double combination(int n, int m);

// calculate permutations or combinations
int main() {
    cout << "Please enter two integers n, m (0 <= m <= n)"
            " and an operator ('p' for permutation, 'c' for combination)\n";
    int n, m;
    char op;
    while (cin >> n >> m >> op) {
        if (m < 0 || m > n) {
            cerr << "m must be between 0 and n" << endl;
            continue;
        }
        if (op != 'p' && op != 'c') {
            cerr << "operator must be 'p' or 'c'" << endl;
            continue;
        }
        cout << (op == 'p' ? permutation(n, m) : combination(n, m)) << endl;
    }
    return 0;
}

// return a * (a+1) * ... * b
double production(int a, int b) {
    double p = 1;
    while (a <= b)
        p *= a++;
    return p;
}

// return P(n, m)
double permutation(int n, int m) {
    return production(n - m + 1, n);
}

// return C(n, m)
double combination(int n, int m) {
    return permutation(n, m) / production(1, m);
}
