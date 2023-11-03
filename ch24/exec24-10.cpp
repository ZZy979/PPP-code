#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int randint(int min, int max) {
    static random_device rd;
    static default_random_engine gen(rd());
    return uniform_int_distribution<>(min, max)(gen);
}

// Take two integers n and d as inputs, call randint(n) d times,
// and output the number of draws for each of [0:n).
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " n d\n";
        return 0;
    }

    int n = stoi(argv[1]), d = stoi(argv[2]);
    vector<int> hist(n);
    for (int i = 0; i < d; ++i)
        ++hist[randint(0, n - 1)];

    for (int i = 0; i < hist.size(); ++i)
        cout << i << '\t' << string(hist[i], '*') << '\n';
    return 0;
}
