#include <gtest/gtest.h>

#include <cstdint>
#include <sstream>

#include "Chrono.h"

using namespace Chrono;

TEST(DateTest, ConstructFromYearMonthDay) {
    struct Test_case {
        int year;
        Month month;
        int day;
    };
    Test_case valid_test_cases[] = {
        {1999, Month::Jul, 21},
        {2000, Month::Feb, 29},
        {2018, Month::Dec, 31},
        {2023, Month::Jan, 1},
        {0, Month::Jan, 1},
        {2147483647, Month::Dec, 31}
    };
    for (const auto& t : valid_test_cases) {
        EXPECT_TRUE(is_valid_date(t.year, t.month, t.day));
        Date d(t.year, t.month, t.day);
        EXPECT_EQ(d.year(), t.year);
        EXPECT_EQ(d.month(), t.month);
        EXPECT_EQ(d.day(), t.day);
    }

    Test_case invalid_test_cases[] = {
        {-1, Month::Jan, 1},
        {2003, Month(-1), 10},
        {2005, Month(13), 8},
        {24, Month::Dec, 2007},
        {2015, Month::Feb, 29},
        {2020, Month::Feb, 30},
        {2023, Month::Jan, 0}
    };
    for (const auto& t : invalid_test_cases) {
        EXPECT_FALSE(is_valid_date(t.year, t.month, t.day));
        EXPECT_THROW(Date(t.year, t.month, t.day), Date::Invalid);
    }
}

TEST(DateTest, ConstructFromYearAndDayOfYear) {
    struct Test_case {
        int year;
        int day_of_year;
        Month expected_month;
        int expected_day_of_month;
    };
    Test_case valid_test_cases[] = {
        {2019, 1, Month::Jan, 1},
        {2019, 60, Month::Mar, 1},
        {2019, 365, Month::Dec, 31},
        {2020, 60, Month::Feb, 29},
        {2020, 366, Month::Dec, 31}
    };
    for (const auto& t : valid_test_cases) {
        Date d(t.year, t.day_of_year);
        EXPECT_EQ(d.year(), t.year);
        EXPECT_EQ(d.month(), t.expected_month);
        EXPECT_EQ(d.day(), t.expected_day_of_month);
        EXPECT_EQ(d.day_of_year(), t.day_of_year);
    }

    Test_case invalid_test_cases[] = {
        {-1, 1}, {2019, 0}, {2019, 366}, {2020, -1}, {2020, 1000}
    };
    for (const auto& t : invalid_test_cases) {
        EXPECT_THROW(Date(t.year, t.day_of_year), Date::Invalid);
    }
}

TEST(DateTest, ConstructFromEpochDay) {
    struct Test_case {
        int64_t epoch_day;
        int expected_year;
        Month expected_month;
        int expected_day;
    };
    Test_case valid_test_cases[] = {
        {19010, 2022, Month::Jan, 18},
        {18628, 2021, Month::Jan, 1},
        {18686, 2021, Month::Feb, 28},
        {18992, 2021, Month::Dec, 31},
        {11016, 2000, Month::Feb, 29},
        {-719528, 0, Month::Jan, 1},
        {0, 1970, Month::Jan, 1},
        {2526968, 8888, Month::Aug, 8},
        {784351576776LL, 2147483647, Month::Dec, 31}
    };
    for (const auto& t : valid_test_cases) {
        Date d(t.epoch_day);
        EXPECT_EQ(d.year(), t.expected_year);
        EXPECT_EQ(d.month(), t.expected_month);
        EXPECT_EQ(d.day(), t.expected_day);
        EXPECT_EQ(d.epoch_days(), t.epoch_day);
    }

    EXPECT_THROW(Date(-719529), Date::Invalid);
}

TEST(DateTest, DayOfWeek) {
    struct Test_case {
        Date d;
        WeekDay expected;
    } test_cases[] = {
        {{2020, Month::Jun, 26}, WeekDay::Friday},
        {{2021, Month::Dec, 21}, WeekDay::Tuesday},
        {{2022, Month::Sep, 21}, WeekDay::Wednesday},
        {{2023, Month::Jan, 7}, WeekDay::Saturday},
        {{1970, Month::Jan, 1}, WeekDay::Thursday},
        {{1, Month::Jan, 1}, WeekDay::Monday}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(t.d.day_of_week(), t.expected);
    }
}

TEST(DateTest, AddYear) {
    struct Test_case {
        Date old_date;
        int years_to_add;
        Date new_date;
    };
    Test_case valid_test_cases[] = {
        {{2018, Month::Oct, 1}, 5, {2023, Month::Oct, 1}},
        {{2022, Month::Jan, 18}, -2, {2020, Month::Jan, 18}},
        {{2020, Month::Feb, 29}, 1, {2021, Month::Feb, 28}},
        {{2023, Month::Jan, 1}, -2023, {0, Month::Jan, 1}},
        {{2023, Month::Jan, 9}, 0, {2023, Month::Jan, 9}}
    };
    for (auto t : valid_test_cases) {
        t.old_date.add_year(t.years_to_add);
        EXPECT_EQ(t.old_date, t.new_date);
    }

    Test_case invalid_test_cases[] = {
        {{2022, Month::Feb, 25}, -9999},
        {{2022, Month::Feb, 25}, 2147481627}
    };
    for (auto t : invalid_test_cases) {
        EXPECT_THROW(t.old_date.add_year(t.years_to_add), Date::Invalid);
    }
}

TEST(DateTest, AddMonth) {
    struct Test_case {
        Date old_date;
        int months_to_add;
        Date new_date;
    };
    Test_case valid_test_cases[] = {
        {{2020, Month::Aug, 26}, 3, {2020, Month::Nov, 26}},
        {{2020, Month::Mar, 31}, -1, {2020, Month::Feb, 29}},
        {{2022, Month::Nov, 30}, 4, {2023, Month::Mar, 30}},
        {{2023, Month::Jan, 1}, -24276, {0, Month::Jan, 1}},
        {{2023, Month::Jan, 9}, 0, {2023, Month::Jan, 9}}
    };
    for (auto t : valid_test_cases) {
        t.old_date.add_month(t.months_to_add);
        EXPECT_EQ(t.old_date, t.new_date);
    }

    Test_case invalid_test_cases[] = {
        {{0, Month::Jan, 8}, -1},
        {{2147483647, Month::Dec, 25}, 1}
    };
    for (auto t : invalid_test_cases) {
        EXPECT_THROW(t.old_date.add_month(t.months_to_add), Date::Invalid);
    }
}

TEST(DateTest, AddDay) {
    struct Test_case {
        Date old_date;
        int days_to_add;
        Date new_date;
    };
    Test_case valid_test_cases[] = {
        {{2022, Month::Dec, 25}, 11, {2023, Month::Jan, 5}},
        {{2021, Month::Feb, 28}, -365, {2020, Month::Feb, 29}},
        {{2020, Month::Feb, 29}, 366, {2021, Month::Mar, 1}},
        {{1, Month::Jan, 1}, -366, {0, Month::Jan, 1}},
        {{2023, Month::Jan, 9}, 0, {2023, Month::Jan, 9}}
    };
    for (auto t : valid_test_cases) {
        t.old_date.add_day(t.days_to_add);
        EXPECT_EQ(t.old_date, t.new_date);
    }

    Test_case invalid_test_cases[] = {
        {{1, Month::Jan, 1}, -367},
        {{2147483647, Month::Dec, 31}, 1}
    };
    for (auto t : invalid_test_cases) {
        EXPECT_THROW(t.old_date.add_day(t.days_to_add), Date::Invalid);
    }
}

TEST(HelperFunctionTest, IsLeapYear) {
    struct Test_case {
        int year;
        bool expected;
    } test_cases[] = {
        {2022, false}, {2020, true}, {1900, false}, {2000, true}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(is_leap_year(t.year), t.expected);
    }
}

TEST(HelperFunctionTest, Equal) {
    Date d1(2022, Month::May, 15), d2(2022, Month::Apr, 15);
    EXPECT_NE(d1, d2);
    d2.add_month(1);
    EXPECT_EQ(d1, d2);
}

TEST(HelperFunctionTest, Output) {
    Date d(1978, Month::Jun, 25);
    std::ostringstream oss;
    oss << d;
    EXPECT_EQ(oss.str(), "(1978,6,25)");
}

TEST(HelperFunctionTest, Input) {
    Date d;
    std::istringstream iss("(2007,12,24)");
    EXPECT_TRUE(iss >> d);
    EXPECT_EQ(d, Date(2007, Month::Dec, 24));

    // incomplete input
    iss.clear();
    iss.str("(2004,7,");
    EXPECT_FALSE(iss >> d);

    // format error
    iss.clear();
    iss.str("(2004-7-5)");
    EXPECT_FALSE(iss >> d);

    // invalid date
    iss.clear();
    iss.str("(2004,13,-5)");
    EXPECT_THROW(iss >> d, Date::Invalid);
}

TEST(HelperFunctionTest, NextSunday) {
    struct Test_case {
        Date today;
        Date expected;
    } test_cases[] = {
        {{2023, Month::Jan, 5}, {2023, Month::Jan, 8}},
        {{2023, Month::Jan, 8}, {2023, Month::Jan, 15}},
        {{2023, Month::Jan, 10}, {2023, Month::Jan, 15}}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(next_Sunday(t.today), t.expected);
    }
}

TEST(HelperFunctionTest, NextWeekday) {
    struct Test_case {
        Date today;
        Date expected;
    } test_cases[] = {
        {{2023, Month::Jan, 5}, {2023, Month::Jan, 6}},
        {{2023, Month::Jan, 6}, {2023, Month::Jan, 9}},
        {{2023, Month::Jan, 7}, {2023, Month::Jan, 9}},
        {{2023, Month::Jan, 8}, {2023, Month::Jan, 9}},
        {{2023, Month::Jan, 9}, {2023, Month::Jan, 10}},
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(next_weekday(t.today), t.expected);
    }
}

TEST(HelperFunctionTest, WeekOfYear) {
    struct Test_case {
        Date d;
        int expected;
    } test_cases[] = {
        {{2018, Month::Apr, 20}, 16},
        {{2019, Month::Jan, 1}, 1},
        {{2020, Month::Feb, 29}, 9},
        {{2021, Month::Dec, 31}, 53},
        {{2022, Month::Jan, 18}, 4},
        {{2023, Month::Nov, 5}, 45}
    };
    for (const auto& t : test_cases) {
        EXPECT_EQ(week_of_year(t.d), t.expected);
    }
}
