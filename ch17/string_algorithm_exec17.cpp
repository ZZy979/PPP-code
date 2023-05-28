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
    while (s[length++]);

    char* t = new char[length + 1];
    for (int i = 0; i < length; ++i)
        t[i] = s[i];
    return t;
}

// finds the first occurrence of C-style string x in s
const char* findx(const char* s, const char* x) {
    for (int i = 0; s[i]; ++i) {
        int j, k;
        for (j = i, k = 0; x[k] && s[j] == x[k]; ++j, ++k);
        if (k > 0 && !x[k])
            return s + i;
    }
    return nullptr;
}
