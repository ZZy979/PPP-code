#include <iostream>
#include <map>
#include <string>

using namespace std;

// make a list of the number of occurrences of words in a text
int main() {
    map<string, int> words;     // keep (word,frequency) pairs

    for (string s; cin >> s;)
        ++words[s];     // note: words is subscripted by a string

    for (const auto& p : words)
        cout << p.first << ": " << p.second << '\n';
    return 0;
}
