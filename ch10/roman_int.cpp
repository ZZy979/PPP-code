#include "roman_int.h"

#include <unordered_map>
#include <vector>

// convert roman number to integer, throws out_of_range if s contains invalid character
int roman_to_int(const std::string& s) {
    static const std::unordered_map<char, int> symbol_values{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int n = 0;
    for (int i = 0; i < s.length(); ++i) {
        int value = symbol_values.at(toupper(s[i]));
        if (i < s.length() - 1 && value < symbol_values.at(toupper(s[i + 1])))
            n -= value;
        else
            n += value;
    }
    return n;
}

// convert integer to roman number
std::string int_to_roman(int n) {
    static const std::vector<std::pair<int, std::string>> value_symbols{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string s;
    for (const auto& p : value_symbols) {
        while (n >= p.first) {
            s += p.second;
            n -= p.first;
        }
        if (n == 0)
            break;
    }
    return s;
}

std::istream& operator>>(std::istream& is, Roman_int& r) {
    std::string s;
    if (is >> s)
        r = Roman_int(s);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Roman_int& r) {
    return os << r.to_string();
}
