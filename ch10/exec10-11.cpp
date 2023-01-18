#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Print the sum of all the whitespace-separated integers in a text file.
// For example, "bears: 17 elephants 9 end" should output "26".
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " filename\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    string s;
    int sum = 0;
    while (ifs >> s)
        try {
            sum += stoi(s);
        }
        catch (invalid_argument&) {}
    cout << sum << endl;
    return 0;
}
