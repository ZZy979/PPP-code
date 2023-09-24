#pragma once

template<class InputIt, class T>
int my_count(InputIt first, InputIt last, const T& value) {
    int n = 0;
    for (; first != last; ++first)
        if (*first == value)
            ++n;
    return n;
}

template<class InputIt, class Pred>
int my_count_if(InputIt first, InputIt last, Pred p) {
    int n = 0;
    for (; first != last; ++first)
        if (p(*first))
            ++n;
    return n;
}
