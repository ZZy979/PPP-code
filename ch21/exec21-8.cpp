#include <iostream>
#include <map>
#include <string>

using namespace std;

// make a list of the number of occurrences of words in a text
// output in order of frequency (rather than in lexicographical order)
int main() {
    map<string, int> words;     // keep (word,frequency) pairs

    for (string s; cin >> s;)
        ++words[s];     // note: words is subscripted by a string

    multimap<int, string> frequency;
    for (const auto& p : words)
        frequency.emplace(p.second, p.first);

    for (const auto& p : frequency)
        cout << p.first << ": " << p.second << '\n';
    return 0;
}
