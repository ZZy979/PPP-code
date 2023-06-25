#pragma once

#include <stdexcept>
#include <vector>

/**
 * applies v1[i]+=v2[i] for each element
 *
 * @throws invalid_argument if v1 and v2 have different sizes
 */
template<class T>
void add(std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("v1 and v2 have different sizes");
    for (int i = 0; i < v1.size(); ++i)
        v1[i] += v2[i];
}
