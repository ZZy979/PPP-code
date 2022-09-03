#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int d;
    string s;
    if (cin >> d) {
        if (d >= 0 && d <= 9)
            cout << numbers[d] << endl;
        else
            cout << "not a number I know\n";
    }
    else {
        cin.clear();
        cin >> s;
        bool found = false;
        for (int i = 0; i < numbers.size(); ++i)
            if (s == numbers[i]) {
                cout << i << endl;
                found = true;
                break;
            }
        if (!found)
            cout << "not a number I know\n";
    }
    return 0;
}
