#pragma once

#include <cstdint>

// Relational represents a rational number with two parts: numerator and denominator
class Relational {
public:
    Relational(int64_t num, int64_t den = 1);

    int64_t num() const { return num_; }
    int64_t den() const { return den_; }

    Relational& operator=(const Relational& other);
    operator double() const { return double(num_) / den_; }
private:
    int64_t num_;
    int64_t den_;
};

constexpr int64_t gcd(int64_t a, int64_t b);
constexpr int sgn(int64_t x);

Relational operator+(const Relational& a, const Relational& b);
Relational operator-(const Relational& a, const Relational& b);
Relational operator*(const Relational& a, const Relational& b);
Relational operator/(const Relational& a, const Relational& b);
Relational operator+(const Relational& a);
Relational operator-(const Relational& a);
bool operator==(const Relational& a, const Relational& b);
bool operator!=(const Relational& a, const Relational& b);
