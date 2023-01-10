#include "Chrono.h"

#include <cmath>
#include <algorithm>

namespace Chrono {

// helper constants:

// number of days in each month
const int DAYS_IN_MONTH[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day-of-year (start from 1) of the first day of each month
const int FIRST_DAY_OF_YEAR[][12] = {
    {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
    {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336}
};

// number of days between 0000-1-1 and 1970-1-1
const int DAYS_0000_TO_1970 = days_in_years(1970);

// number of days in 4 years
const int DAYS_IN_4_YEARS = 4 * 365 + 1;

// number of days in 100 years
const int DAYS_IN_100_YEARS = 25 * DAYS_IN_4_YEARS - 1;

// number of days in a full 400-year period, plus 1 because 0000 is leap year
const int DAYS_IN_400_YEARS = 4 * DAYS_IN_100_YEARS + 1;

// member function definitions:

// construct date from year-month-day, throws Date::Invalid if date is invalid
Date::Date(int yy, Month mm, int dd)
        :y(yy), m(mm), d(dd) {
    if (!is_valid_date(yy, mm, dd))
        throw Invalid();
}

const Date& default_date() {
    static const Date dd(2001, Month::Jan, 1);    // start of 21st century
    return dd;
}

// construct date from default value: 2001-1-1
Date::Date()
        :y(default_date().year()),
        m(default_date().month()),
        d(default_date().day()) {
}

// construct date from year and day-of-year (start from 1)
// throws Date::Invalid if yy or day_of_year is out of range
Date::Date(int yy, int day_of_year) :y(yy) {
    if (yy < 0 || day_of_year <= 0 || day_of_year > (is_leap_year(yy) ? 366 : 365))
        throw Invalid();
    const int* first_day_of_year = FIRST_DAY_OF_YEAR[is_leap_year(yy)];
    auto it = std::upper_bound(first_day_of_year, first_day_of_year + 12, day_of_year) - 1;
    m = Month(it - first_day_of_year);
    d = day_of_year - *it + 1;
}

// construct date from number of days since epoch 1970-1-1 (start from 0)
// throws Date::Invalid if date is before 0000-1-1
Date::Date(int64_t epoch_day) {
    epoch_day += DAYS_0000_TO_1970;     // convert to number of days since 0000-1-1
    if (epoch_day < 0)
        throw Invalid();

    int n400 = epoch_day / DAYS_IN_400_YEARS;
    epoch_day %= DAYS_IN_400_YEARS;     // year in [400k, 400(k+1))

    --epoch_day;    // temporarily view 400k as non-leap year, restore only if year is 400k at last
    int n100 = epoch_day / DAYS_IN_100_YEARS;
    epoch_day %= DAYS_IN_100_YEARS;     // year in [100m, 100(m+1))

    ++epoch_day;    // temporarily view 100m as leap year, restore only if year is 100m at last
    int n4 = epoch_day / DAYS_IN_4_YEARS;
    epoch_day %= DAYS_IN_4_YEARS;       // year in [4n, 4(n+1))

    --epoch_day;    // temporarily view 4n as leap year, restore only if year is 4n at last
    int n1 = epoch_day / 365;
    epoch_day %= 365;

    int year = n400 * 400 + n100 * 100 + n4 * 4 + n1;
    if (year % 4 == 0) ++epoch_day;
    if (year % 100 == 0) --epoch_day;
    if (year % 400 == 0) ++epoch_day;

    *this = Date(year, epoch_day + 1);
}

// return day-of-year (start from 1)
int Date::day_of_year() const {
    return FIRST_DAY_OF_YEAR[is_leap_year(y)][int(m)] + d - 1;
}

// return day-of-week
WeekDay Date::day_of_week() const {
    // 1970-1-1 is Thursday
    return WeekDay(floor_mod(epoch_days() + int(WeekDay::Thursday), 7));
}

// return number of days since epoch 1970-1-1 (start from 0)
int64_t Date::epoch_days() const {
    return days_in_years(y) + day_of_year() - 1 - DAYS_0000_TO_1970;
}

// add n years to date, adjust day-of-month to end of month if necessary
// throws Date::Invalid if new date is before 0000-1-1
void Date::add_year(int n) {
    y += n;
    d = std::min(d, days_in_month(y, m));
    if (y < 0) throw Invalid();
}

// add n months to date, adjust day-of-month to end of month if necessary
// throws Date::Invalid if new date is before 0000-1-1
void Date::add_month(int n) {
    int64_t num_months = int64_t(y) * 12 + int(m);  // January of year 0000 is month 0
    int64_t new_month = num_months + n;
    y = floor_div(new_month, 12);   // use floor division to correctly deal with negative new_month
    m = Month(floor_mod(new_month, 12));
    d = std::min(d, days_in_month(y, m));
    if (y < 0) throw Invalid();
}

// add n days to date, throws Date::Invalid if new date is before 0000-1-1
void Date::add_day(int n) {
    *this = Date(epoch_days() + n);
}

// helper functions:
int64_t floor_div(int64_t x, int64_t y) {
    return floor(double(x) / y);
}

int64_t floor_mod(int64_t x, int64_t y) {
    return x - floor_div(x, y) * y;
}

int days_in_month(int y, Month m) {
    return m >= Month::Jan && m <= Month::Dec ? DAYS_IN_MONTH[is_leap_year(y)][int(m)] : 0;
}

// return number of days between 0000-1-1 and y-1-1, negative if y < 0
int64_t days_in_years(int y) {
    if (y > 0)
        return int64_t(y) * 365 + num_leap_years(y - 1) + 1;    // 0000 is leap year
    else
        return int64_t(y) * 365 - num_leap_years(-y);
}

// true for valid date
bool is_valid_date(int y, Month m, int d) {
    return y >= 0 && m >= Month::Jan && m <= Month::Dec && d > 0 && d <= days_in_month(y, m);
}

bool is_leap_year(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

// return number of leap years between [1, y] (y > 0)
int num_leap_years(int y) {
    return y / 4 - y / 100 + y / 400;
}

bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
}

bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os << '(' << d.year()
            << ',' << int(d.month()) + 1
            << ',' << d.day() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd) {
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {     // oops: format error
        is.clear(std::ios_base::failbit);   // set the fail bit
        return is;
    }

    dd = Date(y, Month(m - 1), d);
    return is;
}

Date next_Sunday(Date d) {
    d.add_day(7 - int(d.day_of_week()));
    return d;
}

Date next_weekday(Date d) {
    WeekDay week_day = d.day_of_week();
    int add = week_day == WeekDay::Friday ? 3 : week_day == WeekDay::Saturday ? 2 : 1;
    d.add_day(add);
    return d;
}

// return week of year, assume that week 1 is the week with January 1 in it
// and that the first day of a week is a Sunday
int week_of_year(const Date& d) {
    WeekDay w = Date(d.year(), Month::Jan, 1).day_of_week();
    return (d.day_of_year() - 1 + int(w)) / 7 + 1;
}

}  // namespace Chrono
