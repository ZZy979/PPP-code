#include <gtest/gtest.h>

#include <sstream>
#include <vector>
#include <stdexcept>

#include "lexer.h"

class TokenStreamTest : public ::testing::Test {
protected:
    TokenStreamTest() :ts(iss) {}

    std::istringstream iss;
    Token_stream ts;
};

TEST_F(TokenStreamTest, Get) {
    iss.str("2; 2+3; 1 +\t2\n* 3; 12.5/(2.3-.4);q");
    std::vector<Token> expected = {
        {number, 2}, {';'},
        {number, 2}, {'+'}, {number, 3}, {';'},
        {number, 1}, {'+'}, {number, 2}, {'*'}, {number, 3}, {';'},
        {number, 12.5}, {'/'}, {'('}, {number, 2.3}, {'-'}, {number, 0.4}, {')'}, {';'},
        {'q'}
    };

    for (Token e : expected) {
        Token t = ts.get();
        EXPECT_EQ(t.kind, e.kind);
        if (t.kind == number)
            EXPECT_DOUBLE_EQ(t.value, e.value);
    }
}

TEST_F(TokenStreamTest, GetBadToken) {
    iss.str("1&2;");
    EXPECT_DOUBLE_EQ(ts.get().value, 1);
    EXPECT_THROW(ts.get(), std::invalid_argument);
}

TEST_F(TokenStreamTest, PutBack) {
    iss.str("+");
    ts.putback({number, 45});
    EXPECT_DOUBLE_EQ(ts.get().value, 45);
    EXPECT_EQ(ts.get().kind, '+');
}

TEST_F(TokenStreamTest, PutBackFull) {
    ts.putback({'-'});
    EXPECT_THROW(ts.putback({number, 42}), std::runtime_error);
}
