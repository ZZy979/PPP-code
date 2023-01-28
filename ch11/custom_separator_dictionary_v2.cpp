#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "punct_stream_v2.h"

using namespace std;

// given text input, produce a sorted list of all words in that text
// ignore punctuation and case differences
// eliminate duplicates from the output
int main() {
    unordered_map<string, string> abbreviations{
        {"don't", "do not"}, {"doesn't", "does not"}, {"didn't", "did not"},
        {"ain't", "am not"}, {"isn't", "is not"}, {"aren't", "are not"},
        {"won't", "will not"}, {"wouldn't", "would not"},
        {"haven't", "have not"}, {"hasn't", "has not"},
        {"can't", "can not"}, {"shouldn't", "should not"}, {"mustn't", "must not"}
    };
    Punct_stream_v2 ps(cin, abbreviations);
    ps.whitespace(";,.?-'\"()");
    ps.case_sensitive(false);

    vector<string> words;
    for (string word; ps >> word;)
        words.push_back(word);              // read words

    sort(words.begin(), words.end());       // sort in lexicographical order
    for (int i = 0; i < words.size(); ++i)  // write dictionary
        if (i == 0 || words[i - 1] != words[i])
            cout << words[i] << '\n';
    return 0;
}
