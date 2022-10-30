#include <gtest/gtest.h>

#include <sstream>
#include <vector>

#include "lexer.h"

class TokenStreamV2Test : public ::testing::Test {
protected:
    TokenStreamV2Test() :ts(iss) {}

    std::istringstream iss;
    Token_stream ts;
};

TEST_F(TokenStreamV2Test, Get) {
    iss.str("2; 2+3*5%4; 1 +\t2\n* 3; 12.5/(2.3-.4);q");
    std::vector<Token> expected = {
        {number, 2}, {';'},
        {number, 2}, {'+'}, {number, 3}, {'*'}, {number, 5}, {'%'}, {number, 4}, {';'},
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

TEST_F(TokenStreamV2Test, GetBadToken) {
    std::vector<std::string> input = {"!", "@", "&", "abc"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(ts.get(), Lexer_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(TokenStreamV2Test, PutBack) {
    iss.str("+");
    ts.putback({number, 45});
    EXPECT_DOUBLE_EQ(ts.get().value, 45);
    EXPECT_EQ(ts.get().kind, '+');
}

TEST_F(TokenStreamV2Test, PutBackFull) {
    ts.putback({'-'});
    EXPECT_THROW(ts.putback({number, 42}), Lexer_error);
}

TEST_F(TokenStreamV2Test, Ignore) {
    iss.str("+");
    ts.putback({number, 45});
    ts.ignore();
    EXPECT_EQ(ts.get().kind, '+');
}
