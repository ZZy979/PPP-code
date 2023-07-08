#include "copy.h"

// copies the elements of an array of ints defined by [f1:e1) into another [f2:f2+(e1–f1))
void copy(int* f1, int* e1, int* f2) {
    while (f1 != e1) *f2++ = *f1++;
}
