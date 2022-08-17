#include <iostream>
#include <string>

using namespace std;

// detect adjacent repeated words in a sequence of words
int main() {
    int number_of_words = 0;
    string previous = " ";  // not a word
    string current;
    while (cin >> current) {
        ++number_of_words;   // increase word count
        if (previous == current)
            cout << "word number " << number_of_words
                 << " repeated: " << current << '\n';
        previous = current;
    }
    return 0;
}
