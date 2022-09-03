#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> names;
    vector<int> scores;
    string name;
    int score;
    cout << "Please enter name and score pairs, enter \"NoName 0\" to stop\n";
    while (cin >> name >> score) {
        if (name == "NoName")
            break;
        names.push_back(name);
        scores.push_back(score);
    }

    cout << "Please enter a query name or score, enter \"q\" to stop\n";
    while (true) {
        if (cin >> score) {
            bool found = false;
            for (int i = 0; i < scores.size(); ++i)
                if (scores[i] == score) {
                    cout << names[i] << ' ';
                    found = true;
                }
            if (found)
                cout << '\n';
            else
                cout << "score not found\n";
        }
        else {
            cin.clear();
            cin >> name;
            if (name == "q")
                break;
            bool found = false;
            for (int i = 0; i < names.size(); ++i)
                if (names[i] == name) {
                    cout << scores[i] << endl;
                    found = true;
                }
            if (!found)
                cout << "name not found\n";
        }
    }
    return 0;
}
