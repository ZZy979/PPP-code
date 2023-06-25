#pragma once

#include <stdexcept>
#include <vector>

/**
 * returns the sum of all vt[i]*vu[i]
 *
 * @throws invalid_argument if vt and vu have different sizes
 * @see ch08/inner_product.cpp
 */
template<class T, class U>
T inner_product(const std::vector<T>& vt, const std::vector<U>& vu, T init = T()) {
    if (vt.size() != vu.size())
        throw std::invalid_argument("vt and vu have different sizes");
    for (int i = 0; i < vt.size(); ++i)
        init = init + vt[i] * vu[i];
    return init;
}
