#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool strptime(const string& s, const string& fmt, tm& t);
string strftime(const tm& t, const string& fmt);

string regex_replace(const string& s, const regex& p, const function<string(const smatch&)>& f);
string reformat_date(const string& s, const regex& p, const string& from_fmt, const string& to_fmt);

// Find all dates and reformat them to the ISO yyyy-mm-dd format.
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

    // 注：gcc 12.1以下的std::get_time()有bug，与标准不一致：%m和%d不接受前导0，%b不接受月份全称，%B不接受月份缩写
    // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=45896
    // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=78714
    // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=89778
    vector<pair<regex, string>> date_patterns = {
        {regex(R"(\d{4}-\d{1,2}-\d{1,2})"), "%Y-%m-%d"},        // 2007-06-05
        {regex(R"(\d{4}/\d{1,2}/\d{1,2})"), "%Y/%m/%d"},        // 2007/06/05
        {regex(R"(\d{1,2}/\d{1,2}/\d{4})"), "%m/%d/%Y"},        // 6/5/2007
        {regex(R"([A-Za-z]+ \d{1,2}, \d{4})"), "%B %d, %Y"},    // June 5, 2007
        {regex(R"(\d{1,2} [A-Za-z]+ \d{4})"), "%d %B %Y"}       // 5 June 2005
    };
    string iso_format = "%Y/%m/%d";
    for (string line; getline(ifs, line);) {
        for (const auto& p : date_patterns)
            line = reformat_date(line, p.first, p.second, iso_format);
        cout << line << '\n';
    }
    return 0;
}

bool strptime(const string& s, const string& fmt, tm& t) {
    istringstream iss(s);
    return bool(iss >> get_time(&t, fmt.c_str()));
}

string strftime(const tm& t, const string& fmt) {
    ostringstream oss;
    oss << put_time(&t, fmt.c_str());
    return oss.str();
}

string regex_replace(const string& s, const regex& p, const function<string(const smatch&)>& f) {
    sregex_iterator it(s.begin(), s.end(), p), end;
    if (it == end)
        return s;

    ostringstream oss;
    ssub_match last;
    for (; it != end; ++it) {
        oss << it->prefix() << f(*it);
        last = it->suffix();
    }
    oss << last;
    return oss.str();
}

string reformat_date(const string& s, const regex& p, const string& from_fmt, const string& to_fmt) {
    return regex_replace(s, p, [&](const smatch& m) {
        tm t{};
        return strptime(m.str(), from_fmt, t) ? strftime(t, to_fmt) : m.str();
    });
}
