#include <iostream>
#include <vector>

#include "get_jack_and_jill_data.h"

using namespace std;

// return a pointer to the element in [first,last) that has the highest value
double* high(double* first, double* last) {
    double h = -1;
    double* high;
    for (double* p = first; p != last; ++p)
        if (h < *p) { high = p; h = *p; }
    return high;
}

// Jack and Jill are each measuring vehicle speeds, which they record as floating-point values.
// Find and print the element with the highest value in each data set.
int main() {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data, jack_data + jack_count);
    vector<double>& v = *jill_data;
    double* jill_high = high(&v[0], &v[0] + v.size());
    cout << "Jill's max: " << *jill_high
            << "; Jack's max: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
    return 0;
}
