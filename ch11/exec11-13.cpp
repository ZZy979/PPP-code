#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Reverse the order of words (defined as whitespace-separated strings) from input.
int main() {
    vector<string> words;
    for (string word; cin >> word;)
        words.push_back(word);

    for (int i = words.size() - 1; i >= 0; --i)
        cout << words[i] << ' ';
    return 0;
}
