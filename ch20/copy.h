#pragma once

void my_copy(int* f1, int* e1, int* f2);

template<class Iter1, class Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1) *f2++ = *f1++;
    return f2;
}
