#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * This file contains data structures to represent a structured file of temperature readings:
 *
 * - A file holds years
 * - A year starts with "{ year" followed by an integer giving the year, zero or more months,
 *   and ends with "}"
 * - A month starts with "{ month" followed by a three-letter month name, zero or more readings,
 *   and ends with "}"
 * - A reading starts with a "(" followed by day of the month, hour of the day, and temperature,
 *   and ends with a ")"
 */

const int not_a_reading = -7777;    // less than absolute zero
const int not_a_month = -1;
const int implausible_min = -200;
const int implausible_max = 200;

// a day of temperature readings
struct Day {
    std::vector<double> hour = std::vector<double>(24, not_a_reading);
};

// a month of temperature readings
struct Month {
    int month = not_a_month;    // [0:11] January is 0
    std::vector<Day> day{32};   // [1:31] one vector of readings per day
};

// a year of temperature readings, organized by month
struct Year {
    int year;                       // positive == A.D.
    std::vector<Month> month{12};   // [0:11] January is 0
};

struct Reading {
    int day;
    int hour;
    double temperature;
};

std::istream& operator>>(std::istream& is, Reading& r);
std::istream& operator>>(std::istream& is, Month& m);
std::istream& operator>>(std::istream& is, Year& y);

int month_to_int(const std::string& s);
std::string int_to_month(int m);
bool is_valid(const Reading& r);
void end_of_loop(std::istream& ist, char terminator, const std::string& message);

std::ostream& operator<<(std::ostream& os, const Reading& r);
std::ostream& operator<<(std::ostream& os, const Month& m);
std::ostream& operator<<(std::ostream& os, const Year& y);
