#include <iostream>
#include <string>

using namespace std;

// Removes all vowels from input ("disemvowels").
int main() {
    string vowels = "AEIOUaeiou";
    char c;
    while (cin.get(c))
        if (vowels.find(c) == string::npos)
            cout << c;
    return 0;
}
