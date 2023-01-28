#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "punct_stream.h"

using namespace std;

// given text input, produce a sorted list of all words in that text
// ignore punctuation and case differences
// eliminate duplicates from the output
int main() {
    Punct_stream ps(cin);
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");  // note \" means " in string
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
