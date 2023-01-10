#pragma once

#include <cstdint>
#include <iostream>

namespace Chrono {

enum class Month {
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

enum class WeekDay {
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

// A date of year-month-day. Valid range is 0000-1-1 to 2147483647-12-31.
class Date {
public:
    class Invalid {};                   // to throw as exception

    Date();                             // default constructor
    Date(int yy, Month mm, int dd);     // check for valid date and initialize
    Date(int yy, int day_of_year);
    explicit Date(int64_t epoch_day);
    // the default copy operations are fine

    // nonmodifying operations:
    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }
    int day_of_year() const;
    WeekDay day_of_week() const;
    int64_t epoch_days() const;

    // modifying operations:
    void add_year(int n);
    void add_month(int n);
    void add_day(int n);
private:
    int y;
    Month m;
    int d;
};

int64_t floor_div(int64_t x, int64_t y);
int64_t floor_mod(int64_t x, int64_t y);

int days_in_month(int y, Month m);
int64_t days_in_years(int y);
bool is_valid_date(int y, Month m, int d);
bool is_leap_year(int y);
int num_leap_years(int y);

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& is, Date& dd);

Date next_Sunday(Date d);
Date next_weekday(Date d);
int week_of_year(const Date& d);

}  // namespace Chrono
