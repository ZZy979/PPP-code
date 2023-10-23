#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

// Find dates in a text file. Write out each line containing at least one date.
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

    vector<regex> date_patterns = {
        regex(R"(\d{4}-\d{1,2}-\d{1,2})"),      // 2007-06-05
        regex(R"(\d{4}/\d{1,2}/\d{1,2})"),      // 2007/06/05
        regex(R"(\d{1,2}/\d{1,2}/\d{4})"),      // 6/5/2007
        regex(R"([A-Za-z]+ \d{1,2}, \d{4})"),   // June 5, 2007
        regex(R"(\d{1,2} [A-Za-z]+ \d{4})")     // 5 June 2005
    };
    string line;
    for (int lineno = 1; getline(ifs, line); ++lineno)
        if (any_of(date_patterns.begin(), date_patterns.end(), [&line](const regex& p) { return regex_search(line, p); }))
            cout << lineno << ": " << line << '\n';
    return 0;
}
