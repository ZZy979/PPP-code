#include "describe_vector.h"

#include <cfloat>
#include <algorithm>
#include <numeric>
#include <stdexcept>

/**
 * return the largest element of v
 *
 * @throws invalid_argument if v is empty
 */
double maxv(const std::vector<double>& v) {
    if (v.empty())
        throw std::invalid_argument("v is empty");

    double largest = DBL_MIN;
    for (double d : v)
        largest = std::max(largest, d);
    return largest;
}

/**
 * return the smallest element, the largest element, mean and median of v
 *
 * @throws invalid_argument if v is empty
 */
Double_result describe(std::vector<double> v) {
    // pass-by-value because median needs to sort v
    if (v.empty())
        throw std::invalid_argument("v is empty");

    std::sort(v.begin(), v.end());
    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double median = v.size() % 2 == 0 ? (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2 : v[v.size() / 2];
    return {v[0], v.back(), sum / v.size(), median};
}

bool compare_by_length(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

/**
 * find the longest and the shortest string and the lexicographically first and last string
 *
 * @returns length of each string
 * @throws invalid_argument if v is empty
 */
std::vector<int> describe(const std::vector<std::string>& v, String_result& result) {
    if (v.empty())
        throw std::invalid_argument("v is empty");

    result = {
        *std::min_element(v.begin(), v.end(), compare_by_length),
        *std::max_element(v.begin(), v.end(), compare_by_length),
        *std::min_element(v.begin(), v.end()),
        *std::max_element(v.begin(), v.end())
    };
    std::vector<int> length(v.size());
    std::transform(v.begin(), v.end(), length.begin(), [](const std::string& s) { return s.length(); });
    return length;
}
