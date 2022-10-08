#include "solve_equation.h"

#include <cmath>
#include <stdexcept>

std::pair<double, double> solve_quadratic_equation(double a, double b, double c) {
    double delta =  b * b - 4 * a * c;
    if (delta < 0)
        throw std::invalid_argument("solve_quadratic_equation: no real roots");
    double p = -b / (2 * a), q = sqrt(delta) / (2 * a);
    return std::make_pair(p + q, p - q);
}
