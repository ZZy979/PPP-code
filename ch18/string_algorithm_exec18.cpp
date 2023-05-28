#include "string_algorithm_exec18.h"

// copy C-style string s into memory allocated on the free store
char* strdup_(const char* s) {
    int length = 0;
    for (const char* p = s; *p++; ++length);

    char* t = new char[length + 1];
    for (char* p = t; *p++ = *s++;);
    return t;
}

// finds the first occurrence of C-style string x in s
const char* findx(const char* s, const char* x) {
    for (const char* p = s; *p; ++p) {
        const char* q, *r;
        for (q = p, r = x; *r && *q == *r; ++q, ++r);
        if (r > x && !*r)
            return p;
    }
    return nullptr;
}

// compares C-style strings, returns a negative number if s1 is lexicographically before s2,
// zero if s1 equals s2, and a positive number if s1 is lexicographically after s2
int strcmp_(const char* s1, const char* s2) {
    for (;*s1 && *s2 && *s1 == *s2; ++s1, ++s2);
    return *s1 - *s2;
}

// concatenates two strings with separator
std::string cat_dot(const std::string& s1, const std::string& s2, const std::string& separator) {
    return s1 + separator + s2;
}

// concatenates two C-style strings with separator, returns a free-store-allocated C-style string
char* cat_dot(const char* s1, const char* s2, const char* separator) {
    int len1 = 0, len2 = 0, lens = 0;
    while (s1[len1++]);
    while (s2[len2++]) ;
    while (separator[lens++]);

    char* p = new char[len1 + lens + len2 + 1];
    char* q = p;
    while (*q++ = *s1++);
    --q;
    while (*q++ = *separator++);
    --q;
    while (*q++ = *s2++);
    return p;
}
