#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// Generate 500 values from normal distribution N(15, 4^2) and write out histogram.
int main() {
    auto gen = bind(normal_distribution<double>(15, 4.0), default_random_engine());
    vector<int> hist(2 * 15);

    // generate histogram of 500 values
    for (int i = 0; i < 500; ++i)
        ++hist[int(round(gen()))];

    // write out histogram
    for (int i = 0; i < hist.size(); ++i)
        cout << i << '\t' << string(hist[i], '*') << '\n';
    return 0;
}
