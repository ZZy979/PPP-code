#include "fibonacci.h"

#include <stdexcept>

/**
 * create a vector of Fibonacci numbers
 *
 * @param x first number
 * @param y second number
 * @param v output vector
 * @param n number of elements to put into v
 * @throws invalid_argument if n < 0
 */
void fibonacci(int x, int y, std::vector<int>& v, int n) {
    if (n < 0)
        throw std::invalid_argument("n can't be negative");
    for (int i = 0; i < n; ++i) {
        v.push_back(x);
        int z = x + y;
        x = y;
        y = z;
    }
}
