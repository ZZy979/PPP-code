#include <iostream>
#include <vector>
#include <string>

using namespace std;

// "bleeps" out words that you don't like
int main() {
    vector<string> disliked = {"cat", "art", "chili"};
    string word;
    while (cin >> word) {
        bool is_disliked = false;
        for (int i = 0; i < disliked.size(); ++i)
            if (word == disliked[i])
                is_disliked = true;
        if (is_disliked)
            cout << "BLEEP" << endl;
        else
            cout << word << endl;
    }
    return 0;
}
