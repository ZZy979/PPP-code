#include <iostream>
#include <vector>

#include "get_jack_and_jill_data.h"
#include "high.h"

using namespace std;

// Jack and Jill are each measuring vehicle speeds, which they record as floating-point values.
// Find and print the element with the highest value in each data set.
int main() {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data, jack_data + jack_count);
    auto jill_high = high(jill_data->begin(), jill_data->end());

    if (jill_high == jill_data->end())
        cout << "Jill's data is empty; ";
    else
        cout << "Jill's max: " << *jill_high << "; ";

    if (jack_high == jack_data + jack_count)
        cout << "Jack's data is empty";
    else
        cout << "Jack's max: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
    return 0;
}
