#include <iostream>

using namespace std;

struct CharTypeCount {
    int (*pf)(int);
    string name;
    int count;
};

// Print out how many characters of each character classification are in input.
int main() {
    CharTypeCount char_types[] = {
        {isspace, "whitespace", 0},
        {isalpha, "alphabetic", 0},
        {isdigit, "decimal digit", 0},
        {isxdigit, "hexadecimal digit", 0},
        {isupper, "uppercase letter", 0},
        {islower, "lowercase letter", 0},
        {isalnum, "alphanumeric", 0},
        {iscntrl, "control character", 0},
        {ispunct, "punctuation", 0},
        {isprint, "printable", 0},
        {isgraph, "graphical", 0}
    };

    char c;
    while (cin.get(c))
        for (CharTypeCount& t : char_types)
            if (t.pf(c))
                ++t.count;

    for (const CharTypeCount& t : char_types)
        cout << t.name << ": " << t.count << endl;
    return 0;
}
