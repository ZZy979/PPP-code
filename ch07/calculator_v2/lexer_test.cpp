#include <gtest/gtest.h>

#include <sstream>
#include <vector>

#include "lexer.h"

class CalculatorV2LexerTest : public ::testing::Test {
protected:
    CalculatorV2LexerTest() :ts(iss) {}

    std::istringstream iss;
    Token_stream ts;
};

TEST_F(CalculatorV2LexerTest, Get) {
    iss.str("2; 2+3*5%4; 1 +\t2\n* 3; 12.5/(2.3-.4);"
            "let var = 7.2; x+y*2;"
            "const a = 1;"
            "sin(pi/6) * pow(a, 3);"
            "Hello world;"
            "srtvrqtiewcbet7rewaewre-wqcntrretewru*754389652743/nvcqnwq;"
            "h"
            "q");
    std::vector<Token> expected = {
        {number, 2}, {print},
        {number, 2}, {'+'}, {number, 3}, {'*'}, {number, 5}, {'%'}, {number, 4}, {print},
        {number, 1}, {'+'}, {number, 2}, {'*'}, {number, 3}, {print},
        {number, 12.5}, {'/'}, {'('}, {number, 2.3}, {'-'}, {number, 0.4}, {')'}, {print},
        {let}, {name, "var"}, {'='}, {number, 7.2}, {print},
        {name, "x"}, {'+'}, {name, "y"}, {'*'}, {number, 2}, {print},
        {constant}, {name, "a"}, {'='}, {number, 1}, {print},
        {name, "sin"}, {'('}, {name, "pi"}, {'/'}, {number, 6}, {')'}, {'*'},
        {name, "pow"}, {'('}, {name, "a"}, {','}, {number, 3}, {')'}, {';'},
        {name, "Hello"}, {name, "world"}, {print},
        {name, "srtvrqtiewcbet7rewaewre"}, {'-'}, {name, "wqcntrretewru"},
        {'*'}, {number, 754389652743.0}, {'/'}, {name, "nvcqnwq"}, {print},
        {help},
        {quit}
    };

    for (Token e : expected) {
        Token t = ts.get();
        EXPECT_EQ(t.kind, e.kind);
        if (t.kind == number)
            EXPECT_DOUBLE_EQ(t.value, e.value);
        else if (t.kind == name)
            EXPECT_EQ(t.name, e.name);
    }
}

TEST_F(CalculatorV2LexerTest, GetBadToken) {
    std::vector<std::string> input = {"!", "@", "&"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(ts.get(), Lexer_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(CalculatorV2LexerTest, PutBack) {
    iss.str("31");
    ts.putback({'+'});
    ts.putback({number, 45});
    EXPECT_DOUBLE_EQ(ts.get().value, 45);
    EXPECT_EQ(ts.get().kind, '+');
    EXPECT_DOUBLE_EQ(ts.get().value, 31);
}

TEST_F(CalculatorV2LexerTest, Ignore) {
    iss.str("+");
    ts.putback({number, 45});
    ts.ignore();
    EXPECT_EQ(ts.get().kind, '+');
}

TEST_F(CalculatorV2LexerTest, IgnoreCharacter) {
    struct Test_case {
        std::string buffer;
        std::string input;
        char ignore;
        Token expected;
    };
    std::vector<Test_case> test_cases = {
        {"", "2*3; 4+5;", print, {number, 4}},
        {"", "1@z; 2+3;", '2', {'+'}},
        {"+;-", "3;", print, {'-'}},
        {"+;", "-3;", print, {'-'}}
    };
    for (const auto& t : test_cases) {
        for (auto it = t.buffer.rbegin(); it != t.buffer.rend(); ++it)
            ts.putback({*it});
        iss.str(t.input);
        ts.ignore(t.ignore);
        Token next = ts.get();
        EXPECT_EQ(next.kind, t.expected.kind);
        if (next.kind == number)
            EXPECT_DOUBLE_EQ(next.value, t.expected.value);
        ts.ignore();
    }
}
