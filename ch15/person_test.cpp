#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

#include "person.h"

TEST(PersonTest, Constructor) {
    Person p("Alice", 24);
    EXPECT_EQ(p.name(), "Alice");
    EXPECT_EQ(p.age(), 24);

    struct Test_case {
        std::string name;
        int age;
    } invalid_test_cases[] = {
        {"Alice", -1},
        {"Bob", 150},
        {"Cindy!", 26},
        {"@Dale", 25}
    };
    for (const Test_case& t : invalid_test_cases)
        EXPECT_THROW(Person(t.name, t.age), std::invalid_argument);
}

TEST(PersonTest, Input) {
    struct Test_case {
        std::string input;
        bool expect_success;
        std::string expected_name;
        int expected_age;
    } test_cases[] = {
        {"Alice 24", true, "Alice", 24},
        {"  Bob\t28yr", true, "Bob", 28},
        {"Cindy", false},
        {"Dale : 25", false},
        {"", false}
    };
    for (const Test_case& t : test_cases) {
        Person p("", 0);
        std::istringstream iss(t.input);
        iss >> p;
        EXPECT_EQ(bool(iss), t.expect_success);
        if (t.expect_success) {
            EXPECT_EQ(p.name(), t.expected_name);
            EXPECT_EQ(p.age(), t.expected_age);
        }
    }
}

TEST(PersonTest, Output) {
    struct Test_case {
        std::string name;
        int age;
        std::string expected;
    } test_cases[] = {
        {"Alice", 24, "Alice 24 years old"},
        {"Bob", 1, "Bob 1 year old"},
        {"Cindy", 0, "Cindy 0 years old"},
        {"Dale", 149, "Dale 149 years old"}
    };
    for (const Test_case& t : test_cases) {
        Person p(t.name, t.age);
        std::ostringstream oss;
        oss << p;
        EXPECT_EQ(oss.str(), t.expected);
    }
}
