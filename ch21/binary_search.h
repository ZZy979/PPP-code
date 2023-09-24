#pragma once

#include <iterator>

template<class Iter, class T>
bool my_binary_search(Iter first, Iter last, const T& value) {
    unsigned count = std::distance(first, last);
    while (count > 0) {
        auto step = count / 2;
        auto mid = std::next(first, step);
        if (*mid < value) {
            first = ++mid;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first != last && *first == value;
}
