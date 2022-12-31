#include "inner_product.h"

#include <stdexcept>

/**
 * compute the sum of all price[i]*weight[i]
 *
 * @throws invalid_argument if price and weight have different size
 */
double inner_product(const std::vector<double>& price, const std::vector<double>& weight) {
    if (price.size() != weight.size())
        throw std::invalid_argument("price and weight have different size");
    double result = 0;
    for (int i = 0; i < price.size(); ++i)
        result += price[i] * weight[i];
    return result;
}
