#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

using namespace std;

struct Row {
    int boy = 0, girl = 0, total = 0;
};

// Read a table, and write a new table where the rows with the same initial digit
// (indicating the year: first grades start with 1) are merged.
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " input_file output_file\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "can't open input file " << argv[1] << endl;
        return 1;
    }

    ofstream ofs(argv[2]);
    if (!ofs) {
        cerr << "can't open output file " << argv[2] << endl;
        return 1;
    }

    regex header(R"(^[\w ]+(\t[\w ]+)*$)");             // header line
    regex row(R"(^(\d+)\w+\t(\d+)\t(\d+)\t(\d+)$)");    // data line

    string line;
    if (getline(ifs, line) && regex_match(line, header))
        ofs << line << '\n';

    map<int, Row> data;  // grade -> (boy, girl, total)
    while (getline(ifs, line)) {
        smatch matches;
        if (!regex_match(line, matches, row))
            continue;

        int grade = stoi(matches[1]);
        data[grade].boy += stoi(matches[2]);
        data[grade].girl += stoi(matches[3]);
        data[grade].total += stoi(matches[4]);
    }

    for (const auto& p : data)
        ofs << p.first << '\t' << p.second.boy << '\t' << p.second.girl << '\t' << p.second.total << '\n';
    return 0;
}
