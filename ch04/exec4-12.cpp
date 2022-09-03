#include <iostream>

using namespace std;

bool is_prime(int x);

// find prime numbers from 1 to max
int main() {
    int max = 100;
    cin >> max;
    for (int i = 2; i <= max; ++i)
        if (is_prime(i))
            cout << i << endl;
    return 0;
}

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
