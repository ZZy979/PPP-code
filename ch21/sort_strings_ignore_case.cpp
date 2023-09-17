#include "sort_strings_ignore_case.h"

#include <algorithm>
#include <cctype>

struct No_case {
    // is lowercase(x) < lowercase(y)?
    bool operator()(const std::string& x, const std::string& y) const {
        for (int i = 0; i < x.length(); ++i) {
            if (i == y.length()) return false;  // y < x
            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if (xx < yy) return true;   // x < y
            if (yy < xx) return false;  // y < x
        }
        if (x.length() == y.length()) return false; // x == y
        return true;    // x < y (fewer characters in x)
    }
};

void sort_strings_ignore_case(std::vector<std::string>& v) {
    std::sort(v.begin(), v.end(), No_case());
}

bool compare_char_ignore_case(char x, char y) {
    return tolower(x) < tolower(y);
}

bool compare_string_ignore_case(const std::string& x, const std::string& y) {
    return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end(), compare_char_ignore_case);
}

void sort_strings_ignore_case2(std::vector<std::string>& v) {
    std::sort(v.begin(), v.end(), compare_string_ignore_case);
}
