#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

#include "punct_stream.h"

class PunctStreamTest : public ::testing::Test {
protected:
    PunctStreamTest() :ps_(iss_) {}

    Punct_stream ps_;
    std::istringstream iss_;
};

TEST_F(PunctStreamTest, InputOperator) {
    ps_.whitespace(";:,.");
    iss_.str(
            "To be, or not to be.\n"
            "  I don't know!\n"
            " \t\n"
            ":foo,,bar...baz;\n"
            "no newline at end");

    std::vector<std::string> v, expected{
        "To", "be", "or", "not", "to", "be",
        "I", "don't", "know!",
        "foo", "bar", "baz",
        "no", "newline", "at", "end"
    };
    for (std::string word; ps_ >> word;)
        v.push_back(word);
    EXPECT_EQ(v, expected);
}

TEST_F(PunctStreamTest, WhiteSpaceGetterSetter) {
    ps_.whitespace(",.");
    EXPECT_TRUE(ps_.is_whitespace(','));
    EXPECT_TRUE(ps_.is_whitespace('.'));
    EXPECT_FALSE(ps_.is_whitespace(';'));

    ps_.add_white(';');
    EXPECT_TRUE(ps_.is_whitespace(';'));
}

TEST_F(PunctStreamTest, CaseSensitive) {
    EXPECT_TRUE(ps_.is_case_sensitive());

    ps_.whitespace("!");
    ps_.case_sensitive(false);
    iss_.str("Man bites dog!\n");
    EXPECT_FALSE(ps_.is_case_sensitive());

    std::vector<std::string> v, expected{"man", "bites", "dog"};
    for (std::string word; ps_ >> word;)
        v.push_back(word);
    EXPECT_EQ(v, expected);
}
