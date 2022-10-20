#include <iostream>
#include <vector>
#include <string>

using namespace std;

// compose an integer 0~9999 into digits
int main() {
    cout << "Please enter a number between 0 and 9999" << endl;
    vector<string> units = {"one", "ten", "hundred", "thousand"};
    string s;
    while (cin >> s) {
        try {
            int x = stoi(s);
            if (x < 0 || x > 9999)
                throw out_of_range("");
            cout << s << " is ";
            for (int i = 0; i < s.size(); ++i) {
                cout << s[i] << ' ' << units[s.size() - 1 - i] << (s[i] > '1' ? "s" : "");
                cout << (i < s.size() - 1 ? " and " : "\n");
            }
        }
        catch (invalid_argument&) {
            cerr << "invalid number" << endl;
        }
        catch (out_of_range&) {
            cerr << "number must be between 0 and 9999" << endl;
        }
    }
    return 0;
}
