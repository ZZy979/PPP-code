#include "reverse_vector.h"

// produce a new vector with reversed elements of v
std::vector<int> reverse_copy(const std::vector<int>& v) {
    return std::vector<int>(v.rbegin(), v.rend());
}

// reverse elements of v in place
void reverse_in_place(std::vector<int>& v) {
    for (int i = 0, j = v.size() - 1; i < j; ++i, --j)
        std::swap(v[i], v[j]);
}

// produce a new vector with reversed elements of v
std::vector<std::string> reverse_copy(const std::vector<std::string>& v) {
    return std::vector<std::string>(v.rbegin(), v.rend());
}

// reverse elements of v in place
void reverse_in_place(std::vector<std::string>& v) {
    for (int i = 0, j = v.size() - 1; i < j; ++i, --j)
        std::swap(v[i], v[j]);
}
