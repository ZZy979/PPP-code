#include "factorial.h"

long long factorial_iterative(int n) {
    long long r = 1;
    while (n > 1)
        r *= n--;
    return r;
}

long long factorial_recursive(int n) {
    return n > 1 ? n * factorial_recursive(n - 1) : 1;
}
