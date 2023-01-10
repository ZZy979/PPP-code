#include "relational.h"

#include <cmath>
#include <stdexcept>

// construct Relational from numerator and denominator,
// divide numerator and denominator by greatest common divisor,
// denominator is always positive,
// throws invalid_argument if denominator is 0
Relational::Relational(int64_t num, int64_t den) {
    if (den == 0)
        throw std::invalid_argument("den can't be 0");
    int64_t g = gcd(llabs(num), llabs(den));
    num_ = num * sgn(den) / g;
    den_ = llabs(den) / g;
}

Relational& Relational::operator=(const Relational& other) {
    num_ = other.num_;
    den_ = other.den_;
    return *this;
}

constexpr int64_t gcd(int64_t a, int64_t b) {
    return b == 0 ? a : gcd(b, a % b);
}

constexpr int sgn(int64_t x) {
    return x < 0 ? -1 : 1;
}

Relational operator+(const Relational& a, const Relational& b) {
    return Relational(a.num() * b.den() + b.num() * a.den(), a.den() * b.den());
}

Relational operator-(const Relational& a, const Relational& b) {
    return Relational(a.num() * b.den() - b.num() * a.den(), a.den() * b.den());
}

Relational operator*(const Relational& a, const Relational& b) {
    return Relational(a.num() * b.num(), a.den() * b.den());
}

Relational operator/(const Relational& a, const Relational& b) {
    return Relational(a.num() * b.den(), b.num() * a.den());
}

Relational operator+(const Relational& a) {
    return a;
}

Relational operator-(const Relational& a) {
    return Relational(-a.num(), a.den());
}

bool operator==(const Relational& a, const Relational& b) {
    return a.num() == b.num() && a.den() == b.den();
}

bool operator!=(const Relational& a, const Relational& b) {
    return !(a == b);
}
