#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>
#include <random>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

template<class C>
system_clock::duration time_ordered_insert(C& c, int N) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, N - 1);

    auto start = system_clock::now();
    for (int i = 0; i < N; ++i) {
        int x = distribution(generator);
        auto it = find_if(c.begin(), c.end(), [x](int y) { return y > x; });
        c.insert(it, x);
    }
    auto stop = system_clock::now();
    return stop - start;
}

// Generate N random int values in the range [0:N), insert into a vector and keep it sorted.
// Then do the same for a list. Compare the time they take.
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " N" << endl;
        return 0;
    }

    const int N = stoi(argv[1]);
    using double_seconds = duration<double, seconds::period>;

    vector<int> v;
    system_clock::duration vector_time = time_ordered_insert(v, N);
    cout << "vector takes " << duration_cast<double_seconds>(vector_time).count() << " s" << endl;

    list<int> l;
    system_clock::duration list_time = time_ordered_insert(l, N);
    cout << "list takes " << duration_cast<double_seconds>(list_time).count() << " s" << endl;
    return 0;
}
