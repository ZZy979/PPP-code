#include <iostream>
#include <vector>

#include "get_jack_and_jill_data.h"

using namespace std;

// Jack and Jill are each measuring vehicle speeds, which they record as floating-point values.
// Find and print the element with the highest value in each data set.
int main() {
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data = get_from_jill();

    double h = -1;
    double* jack_high;  // jack_high will point to the element with the highest value
    double* jill_high;  // jill_high will point to the element with the highest value
    for (int i = 0; i < jack_count; ++i)
        if (h < jack_data[i]) {
            jack_high = &jack_data[i];  // save address of largest element
            h = jack_data[i];           // update "largest element"
        }

    h = -1;
    for (int i = 0; i < jill_data->size(); ++i)
        if (h < (*jill_data)[i]) {
            jill_high = &(*jill_data)[i];   // save address of largest element
            h = (*jill_data)[i];            // update "largest element"
        }

    cout << "Jill's max: " << *jill_high
            << "; Jack's max: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
    return 0;
}
