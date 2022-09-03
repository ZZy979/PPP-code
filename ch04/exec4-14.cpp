#include <iostream>
#include <vector>

using namespace std;

// find prime numbers from 1 to max by Sieve of Eratosthenes
int main() {
    int max = 100;
    cin >> max;

    vector<bool> is_prime(max + 1, true);
    for (int i = 2; i * i <= max; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= max; j += i)
                is_prime[j] = false;

    for (int i = 2; i <= max; ++i)
        if (is_prime[i])
            cout << i << endl;
    return 0;
}
