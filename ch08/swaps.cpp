#include "swaps.h"

void swap_v(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int& a, const int& b) {
    // 编译错误 error: assignment of read-only reference 'a'
    // int temp = a;
    // a = b;
    // b = temp;
}
