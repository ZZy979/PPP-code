#include "palindrome.h"

#include <cstring>
#include <algorithm>

bool is_palindrome(const std::string& s) {
    int first = 0;              // index of first letter
    int last = s.length() - 1;  // index of last letter
    while (first < last) {      // we haven't reached the middle
        if (s[first] != s[last]) return false;
        ++first;    // move forward
        --last;     // move backward
    }
    return true;
}

// s points to the first character of an array of n characters
bool is_palindrome(const char s[], int n) {
    int first = 0;              // index of first letter
    int last = n - 1;           // index of last letter
    while (first < last) {      // we haven't reached the middle
        if (s[first] != s[last]) return false;
        ++first;    // move forward
        --last;     // move backward
    }
    return true;
}

// first points to the first letter, last to the last letter
bool is_palindrome(const char* first, const char* last) {
    while (first < last) {      // we haven't reached the middle
        if (*first != *last) return false;
        ++first;    // move forward
        --last;     // move backward
    }
    return true;
}

bool is_palindrome2(const std::string& s) {
    return std::string(s.rbegin(), s.rend()) == s;
}

bool is_palindrome2(const char* s, int n) {
    char* r = new char[n + 1]{'\0'};
    std::reverse_copy(s, s + n, r);
    bool res = strcmp(s, r) == 0;
    delete[] r;
    return res;
}

bool is_palindrome2(const char* first, const char* last) {
    char* r = new char[last - first + 2]{'\0'};
    std::reverse_copy(first, last + 1, r);
    bool res = strcmp(first, r) == 0;
    delete[] r;
    return res;
}
