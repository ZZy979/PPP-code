#include <cctype>
#include <iostream>
#include <string>

using namespace std;

struct CharTypeFunction {
    int (*pf)(int);
    string name;
} char_types[] = {
    {isspace, "whitespace"},
    {isalpha, "alphabetic"},
    {isdigit, "decimal digit"},
    {isxdigit, "hexadecimal digit"},
    {isupper, "uppercase letter"},
    {islower, "lowercase letter"},
    {isalnum, "alphanumeric"},
    {iscntrl, "control character"},
    {ispunct, "punctuation"},
    {isprint, "printable"},
    {isgraph, "graphical"}
};

// Output the classification of each character.
int main() {
    char c;
    while (cin.get(c)) {
        cout << '\'' << c << "' is ";
        for (const CharTypeFunction& f : char_types)
            if (f.pf(c))
                cout << f.name << ',';
        cout << endl;
    }
    return 0;
}
