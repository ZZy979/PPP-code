#include "get_jack_and_jill_data.h"

#include <iostream>

double* get_from_jack(int* count) {
    if (!(std::cin >> *count) || *count <= 0)
        return nullptr;

    auto data = new double[*count];
    for (int i = 0; i < *count; ++i)
        std::cin >> data[i];
    return data;
}

std::vector<double>* get_from_jill() {
    int count;
    if (!(std::cin >> count) || count <= 0)
        return nullptr;

    auto data = new std::vector<double>(count);
    for (int i = 0; i < count; ++i)
        std::cin >> (*data)[i];
    return data;
}
