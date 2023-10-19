#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

void error(const string& msg) {
    throw runtime_error(msg);
}

// Verify that this table is properly laid out (i.e., every row has the right number of fields)
// Verify that the numbers add up (the last line claims to be the sum of the columns above)
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " filename\n";
        return 0;
    }

    try {
        ifstream in(argv[1]);
        if (!in) error("no input file");

        string line;    // input buffer
        int lineno = 0;

        regex header(R"(^[\w ]+(\t[\w ]+)*$)");             // header line
        regex row(R"(^([\w ]+)(\t\d+)(\t\d+)(\t\d+)$)");    // data line

        if (getline(in, line)) {        // check header line
            if (!regex_match(line, header))
                error("no header");
        }

        // column totals:
        int boys = 0, girls = 0;

        while (getline(in, line)) {
            ++lineno;
            smatch matches;
            if (!regex_match(line, matches, row))
                error("bad line: " + to_string(lineno));

            if (in.eof()) cout << "at eof\n";

            // check row:
            int curr_boy = stoi(matches[2]);
            int curr_girl = stoi(matches[3]);
            int curr_total = stoi(matches[4]);
            if (curr_boy + curr_girl != curr_total) error("bad row sum");

            if (matches[1] == "Alle klasser") {     // last line
                if (curr_boy != boys) error("boys don't add up");
                if (curr_girl != girls) error("girls don't add up");
                if (!(in >> ws).eof()) error("characters after total line");
                return 0;
            }

            // update totals:
            boys += curr_boy;
            girls += curr_girl;
        }
        error("didn't find total line");
    }
    catch (runtime_error& e) {
        cerr << e.what() << '\n';
        return 1;
    }
}
