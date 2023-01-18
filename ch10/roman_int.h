#pragma once

#include <iostream>
#include <string>

int roman_to_int(const std::string& s);
std::string int_to_roman(int n);

class Roman_int {
public:
    Roman_int() :n(0) {}
    Roman_int(const std::string& s) :s(s), n(roman_to_int(s)) {}
    Roman_int(int n) :s(int_to_roman(n)), n(n) {}

    int as_int() const { return n; }
    operator int() const { return n; }
    const std::string& to_string() const { return s; }
    operator std::string() const { return s; }

private:
    std::string s;
    int n;
};

std::istream& operator>>(std::istream& is, Roman_int& r);
std::ostream& operator<<(std::ostream& os, const Roman_int& r);
