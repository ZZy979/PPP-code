#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Name_value {
public:
    string name;
    int score;
};

int main() {
    vector<Name_value> persons;
    string name;
    int score;
    cout << "Please enter name and score pairs, enter \"NoName 0\" to stop\n";
    while (cin >> name >> score) {
        if (name == "NoName")
            break;
        persons.push_back({name, score});
    }

    cout << "Please enter a query name or score, enter \"q\" to stop\n";
    while (true) {
        if (cin >> score) {
            bool found = false;
            for (const Name_value& p : persons)
                if (p.score == score) {
                    cout << p.name << ' ';
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
            for (const Name_value& p : persons)
                if (p.name == name) {
                    cout << p.score << endl;
                    found = true;
                }
            if (!found)
                cout << "name not found\n";
        }
    }
    return 0;
}
