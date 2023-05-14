#include "string_algorithm_exec17.h"

// replace all uppercase characters in C-style string s with their lowercase equivalents
void to_lower(char* s) {
    for (; *s; ++s)
        if (*s >= 'A' && *s <= 'Z')
            *s += 'a' - 'A';
}

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
