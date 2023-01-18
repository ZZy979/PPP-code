#include <fstream>
#include <iostream>

using namespace std;

// print the sum of all the numbers in a file of whitespace-separated integers
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

    int n, sum = 0;
    while (ifs >> n)
        sum += n;
    cout << sum << endl;
    return 0;
}
