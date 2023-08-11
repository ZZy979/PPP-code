#pragma once

// return a pointer to the element in [first,last) that has the highest value
template<class Iterator>
Iterator high(Iterator first, Iterator last) {
    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
        if (*high < *p) high = p;
    return high;
}
