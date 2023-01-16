#include "temperature_reading.h"

#include <algorithm>
#include <stdexcept>

// read a temperature reading from is into r
// format: ( 3 4 9.7 )
// check format, but don't bother with data validity
std::istream& operator>>(std::istream& is, Reading& r) {
    char ch1;
    if (is >> ch1 && ch1 != '(') {  // could it be a Reading?
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    char ch2;
    int d, h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')')  // messed-up reading
        throw std::runtime_error("bad reading");
    r = {d, h, t};
    return is;
}

// read a month from is into m
// format: { month feb ... }
std::istream& operator>>(std::istream& is, Month& m) {
    char ch = 0;
    if (is >> ch && ch != '{') {
        is.unget();
        is.clear(std::ios_base::failbit);   // we failed to read a Month
        return is;
    }

    std::string month_marker, mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month")
        throw std::runtime_error("bad start of month");
    m.month = month_to_int(mm);

    int duplicates = 0, invalids = 0;
    for (Reading r; is >> r;) {
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++duplicates;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
            ++invalids;
    }
    if (invalids > 0)
        throw std::runtime_error("invalid readings in month: " + std::to_string(invalids));
    if (duplicates > 0)
        throw std::runtime_error("duplicate readings in month: " + std::to_string(duplicates));
    end_of_loop(is, '}', "bad end of month");
    return is;
}

// read a year from is into y
// format: { year 1972 ... }
std::istream& operator>>(std::istream& is, Year& y) {
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    std::string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year")
        throw std::runtime_error("bad start of year");
    y.year = yy;

    while (true) {
        Month m;    // get a clean m each time around
        if (!(is >> m)) break;
        y.month[m.month] = m;
    }
    end_of_loop(is, '}', "bad end of year");
    return is;
}

std::vector<std::string> month_input_tbl{
    "jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec"
};

// is s the name of a month? If so return its index [0:11] otherwise –1
int month_to_int(const std::string& s) {
    auto it = std::find(month_input_tbl.begin(), month_input_tbl.end(), s);
    return it == month_input_tbl.end() ? not_a_month : it - month_input_tbl.begin();
}

std::string int_to_month(int m) {
    return month_input_tbl[m];
}

// a rough test
bool is_valid(const Reading& r) {
    return r.day >= 1 && r.day <= 31
            && r.hour >= 0 && r.hour <= 23
            && r.temperature >= implausible_min && r.temperature <= implausible_max;
}

void end_of_loop(std::istream& ist, char terminator, const std::string& message) {
    if (ist.fail()) {  // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist >> ch && ch == terminator) return;  // all is fine
        throw std::runtime_error(message);
    }
}

std::ostream& operator<<(std::ostream& os, const Reading& r) {
    return os << '(' << r.day << ' ' << r.hour << ' ' << r.temperature << ')';
}

std::ostream& operator<<(std::ostream& os, const Month& m) {
    os << "{ month " << int_to_month(m.month) << ' ';
    for (int d = 0; d < m.day.size(); ++d)
        for (int h = 0; h < m.day[d].hour.size(); ++h)
            if (m.day[d].hour[h] != not_a_reading)
                os << Reading{d, h, m.day[d].hour[h]} << ' ';
    os << '}';
    return os;
}

std::ostream& operator<<(std::ostream& os, const Year& y) {
    os << "{ year " << y.year << ' ';
    for (const Month& m : y.month)
        if (m.month != not_a_month)
            os << m << ' ';
    os << '}';
    return os;
}
