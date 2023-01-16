#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "temperature_reading.h"

TEST(TemperatureReadingTest, InputReadingFail) {
    std::vector<std::string> input{"{3 4 9.7}", "[3 4 9.7]", "3 4 9.7"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Reading r;
        EXPECT_FALSE(iss >> r);
        EXPECT_TRUE(iss.fail());
    }
}

TEST(TemperatureReadingTest, InputReadingBadReading) {
    std::vector<std::string> input{
        "", "(", "(3", "(3 4", "(3 4 9.7", "(3 4 9.7}",
        "(3,4,9.7)", "(a 4 9.7)", "(3 4)", "(9.7)", "(3x+2y)"
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Reading r;
        EXPECT_THROW(iss >> r, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputReadingSuccess) {
    std::vector<std::string> input{"(3 4 9.7)", "  ( 3 4 9.7  ) ", "(3\t4\n9.7)"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Reading r;
        EXPECT_TRUE(iss >> r);
        EXPECT_EQ(r.day, 3);
        EXPECT_EQ(r.hour, 4);
        EXPECT_DOUBLE_EQ(r.temperature, 9.7);
    }
}

TEST(TemperatureReadingTest, InputMonthFail) {
    std::vector<std::string> input{"( month jan )", "[ month jan ]", "month jan"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Month m;
        EXPECT_FALSE(iss >> m);
        EXPECT_TRUE(iss.fail());
    }
}

TEST(TemperatureReadingTest, InputMonthBadStart) {
    std::vector<std::string> input{"", "{", "{ month", "{ year jan"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Month m;
        EXPECT_THROW(iss >> m, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputMonthInvalid) {
    std::vector<std::string> input{
        "{ month jan (0 4 9.7) }", "{ month jan (32 4 9.7) }",
        "{ month jan (3 -1 9.7) }", "{ month jan (3 24 9.7) }",
        "{ month jan (3 4 -225) }", "{ month jan (3 4 325) }"
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Month m;
        EXPECT_THROW(iss >> m, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputMonthDuplicate) {
    std::vector<std::string> input{
        "{ month jan (3 4 9.7) (3 5 12.4) (3 4 8.6) }",
        "{ month jan (3 4 9.7) (3 4 12.4) (3 4 8.6) }",
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Month m;
        EXPECT_THROW(iss >> m, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputMonthBadEnd) {
    std::vector<std::string> input{
        "{ month jan (3 4 9.7) (3 5 12.4) (3 6 8.6) )",
        "{ month jan (3 4 9.7) (3 5 12.4) (3 6 8.6) ]",
        "{ month jan (3 4 9.7) (3 5 12.4) (3 6 8.6) $",
        "{ month jan (3 4 9.7) (3 5 12.4) (3 6 8.6)",
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Month m;
        EXPECT_THROW(iss >> m, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputMonthBadMonthName) {
    std::istringstream iss("{ month jam (3 4 9.7) (3 5 12.4) (3 6 8.6) }");
    Month m;
    EXPECT_TRUE(iss >> m);
    EXPECT_EQ(m.month, not_a_month);
}


TEST(TemperatureReadingTest, InputMonthSuccess) {
    std::istringstream iss("{ month jan (3 4 9.7) (3 5 12.4) (4 6 8.6) }");
    std::vector<double> no_data(24, not_a_reading);
    Month m;
    EXPECT_TRUE(iss >> m);
    EXPECT_EQ(m.month, 0);
    EXPECT_DOUBLE_EQ(m.day[3].hour[4], 9.7);
    EXPECT_DOUBLE_EQ(m.day[3].hour[5], 12.4);
    EXPECT_DOUBLE_EQ(m.day[4].hour[6], 8.6);
    EXPECT_EQ(m.day[31].hour, no_data);

    iss.str("{ month feb }");
    Month m2;
    EXPECT_TRUE(iss >> m2);
    EXPECT_EQ(m2.month, 1);
    for (const Day& d : m2.day)
        EXPECT_EQ(d.hour, no_data);
}

TEST(TemperatureReadingTest, InputYearFail) {
    std::vector<std::string> input{"", "( year 2023 )", "[ year 2023 ]", "year 2023"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Year y;
        EXPECT_FALSE(iss >> y);
        EXPECT_TRUE(iss.fail());
    }
}

TEST(TemperatureReadingTest, InputYearBadStart) {
    std::vector<std::string> input{"{", "{ year", "{ month 2023", "{ year jan"};
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Year y;
        EXPECT_THROW(iss >> y, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputYearBadEnd) {
    std::vector<std::string> input{
        "{ year 2023 { month jan (3 4 9.7) } )",
        "{ year 2023 { month jan (3 4 9.7) } ]",
        "{ year 2023 { month jan (3 4 9.7) } $",
        "{ year 2023 { month jan (3 4 9.7) }",
    };
    for (const std::string& s : input) {
        std::istringstream iss(s);
        Year y;
        EXPECT_THROW(iss >> y, std::runtime_error);
    }
}

TEST(TemperatureReadingTest, InputYearSuccess) {
    std::istringstream iss(R"({year 2000
        { month feb (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)}
        {month dec (15 15 -9.2 ) (15 14 -8.8) (14 0 -2) }
    })");
    std::vector<double> no_data(24, not_a_reading);
    Year y;
    EXPECT_TRUE(iss >> y);
    EXPECT_EQ(y.year, 2000);
    EXPECT_EQ(y.month[1].month, 1);
    EXPECT_DOUBLE_EQ(y.month[1].day[1].hour[1], 68);
    EXPECT_DOUBLE_EQ(y.month[1].day[2].hour[3], 66.66);
    EXPECT_DOUBLE_EQ(y.month[1].day[1].hour[0], 67.2);
    EXPECT_EQ(y.month[11].month, 11);
    EXPECT_DOUBLE_EQ(y.month[11].day[15].hour[15], -9.2);
    EXPECT_DOUBLE_EQ(y.month[11].day[15].hour[14], -8.8);
    EXPECT_DOUBLE_EQ(y.month[11].day[14].hour[0], -2);
    EXPECT_EQ(y.month[11].day[16].hour, no_data);

    iss.str("{ year 2023 }");
    Year y2;
    EXPECT_TRUE(iss >> y2);
    EXPECT_EQ(y2.year, 2023);
    for (const Month& m : y2.month)
        for (const Day& d : m.day)
            EXPECT_EQ(d.hour, no_data);
}

TEST(TemperatureReadingTest, OutputReading) {
    Reading r{3, 4, 9.7};
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "(3 4 9.7)");
}

TEST(TemperatureReadingTest, OutputMonth) {
    Month m;
    m.month = 7;
    m.day[1].hour[9] = 25.6;
    m.day[2].hour[10] = 27.4;
    m.day[3].hour[11] = 29.3;

    std::ostringstream oss;
    oss << m;
    EXPECT_EQ(oss.str(), "{ month aug (1 9 25.6) (2 10 27.4) (3 11 29.3) }");
}

TEST(TemperatureReadingTest, OutputYear) {
    Year y;
    y.year = 2022;

    Month& jul = y.month[6];
    jul.month = 6;
    jul.day[5].hour[20] = 20.37;
    jul.day[6].hour[22] = 16.92;
    jul.day[5].hour[21] = 18.44;

    Month& nov = y.month[10];
    nov.month = 10;
    nov.day[29].hour[1] = -9.15;
    nov.day[29].hour[0] = -8.26;
    nov.day[30].hour[2] = -10.46;

    std::ostringstream oss;
    oss << y;
    std::string expected = "{ year 2022 { month jul (5 20 20.37) (5 21 18.44) (6 22 16.92) } "
                           "{ month nov (29 0 -8.26) (29 1 -9.15) (30 2 -10.46) } }";
    EXPECT_EQ(oss.str(), expected);
}
