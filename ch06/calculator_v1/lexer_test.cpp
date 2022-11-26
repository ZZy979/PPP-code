#include <gtest/gtest.h>

#include <sstream>
#include <vector>

#include "lexer.h"

class CalculatorV1LexerTest : public ::testing::Test {
protected:
    CalculatorV1LexerTest() :ts(iss) {}

    std::istringstream iss;
    Token_stream ts;
};

TEST_F(CalculatorV1LexerTest, Get) {
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

TEST_F(CalculatorV1LexerTest, GetBadToken) {
    iss.str("1&2;");
    EXPECT_DOUBLE_EQ(ts.get().value, 1);
    EXPECT_THROW(ts.get(), Lexer_error);
}

TEST_F(CalculatorV1LexerTest, PutBack) {
    iss.str("+");
    ts.putback({number, 45});
    EXPECT_DOUBLE_EQ(ts.get().value, 45);
    EXPECT_EQ(ts.get().kind, '+');
}

TEST_F(CalculatorV1LexerTest, PutBackFull) {
    ts.putback({'-'});
    EXPECT_THROW(ts.putback({number, 42}), Lexer_error);
}

TEST_F(CalculatorV1LexerTest, Ignore) {
    iss.str("+");
    ts.putback({number, 45});
    ts.ignore();
    EXPECT_EQ(ts.get().kind, '+');
}
