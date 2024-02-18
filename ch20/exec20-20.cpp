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
std::pair<system_clock::duration, system_clock::duration> time_ordered_insert(C& c, int N) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, N - 1);

    auto start = system_clock::now();
    auto insert_time = system_clock::duration::zero();
    for (int i = 0; i < N; ++i) {
        int x = distribution(generator);
        auto it = find_if(c.begin(), c.end(), [x](int y) { return y > x; });
        auto before_insert = system_clock::now();
        c.insert(it, x);
        insert_time += system_clock::now() - before_insert;
    }
    auto total_time = system_clock::now() - start;
    return std::make_pair(total_time, insert_time);
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
    auto vector_time = time_ordered_insert(v, N);
    cout << "vector total time: " << duration_cast<double_seconds>(vector_time.first).count() << " s, "
            << "insert time: " << duration_cast<double_seconds>(vector_time.second).count() << " s" << endl;

    list<int> l;
    auto list_time = time_ordered_insert(l, N);
    cout << "list total time: " << duration_cast<double_seconds>(list_time.first).count() << " s, "
            << "insert time: " << duration_cast<double_seconds>(list_time.second).count() << " s" << endl;
    return 0;
}
