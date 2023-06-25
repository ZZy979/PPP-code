#pragma once

#include <iostream>

template<class T>
class Number {
public:
    Number(T value = T()) :value_(value) {}

    T& value() { return value_; }
    T value() const { return value_; }
    operator T() const { return value_; }

    Number operator+(const Number& b) const { return value_ + b.value_; }
    Number operator-(const Number& b) const { return value_ - b.value_; }
    Number operator*(const Number& b) const { return value_ * b.value_; }
    Number operator/(const Number& b) const { return value_ / b.value_; }
    Number operator%(const Number& b) const { return value_ % b.value_; }

private:
    T value_;
};

using Int = Number<int>;

template<class T>
std::istream& operator>>(std::istream& is, Number<T>& a) {
    return is >> a.value();
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Number<T>& a) {
    return os << a.value();
}
