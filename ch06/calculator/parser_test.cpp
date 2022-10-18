#include <gtest/gtest.h>

#include <sstream>
#include <vector>
#include <string>

#include "lexer.h"
#include "parser.h"

class ParserTest : public ::testing::Test {
protected:
    ParserTest() :ts(iss), parser(ts) {}

    std::istringstream iss;
    Token_stream ts;
    Parser parser;
};

TEST_F(ParserTest, Expression) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"8;", 8},
        {"1+2*3;", 7},
        {"1-2*3+4;", -1},
        {"1-34/50;", 0.32},
        {"42+(11-4)/8-9*(32.5+24.7);", -471.925}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.expression(), t.second);
        ts.ignore();
    }
}

TEST_F(ParserTest, ExpressionLexerError) {
    std::vector<std::string> input = {
        "!+2", "1*2/3%4+5-6;", "'a';", "1@2", "[2.5]",
        "Mary had a little lamb",
        "srtvrqtiewcbet7rewaewre–wqcntrretewru754389652743nvcqnwq;",
        "!@#$%^&*()~:;"
    };
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.expression(), Lexer_error);
        ts.ignore();
    }
}

TEST_F(ParserTest, ExpressionParserError) {
    std::vector<std::string> input = {
        ";;;", "(1+3;", "(1+);", "();", "1+;", "+1;", "1++;", "1/0;",
        "1++2;", "-2;", "q", "1+q"
    };
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.expression(), Parser_error);
        ts.ignore();
    }
}

TEST_F(ParserTest, Term) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"3.14;", 3.14},
        {"2*3/4;", 1.5},
        {"(1+2)*(3-4*5)/8;", -6.375}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.term(), t.second);
        ts.ignore();
    }
}

TEST_F(ParserTest, TermDevidedByZero) {
    std::vector<std::string> input = {"1/0;", "3/(8-4*2);"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.term(), Parser_error);
        ts.ignore();
    }
}

TEST_F(ParserTest, TermPutBack) {
    std::vector<std::pair<std::string, char>> test_cases = {
        {"2*3/4;", ';'},
        {"1+2*3;", '+'},
        {"(1+2*3);", ';'},
        {"1/2-3", '-'}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        parser.term();
        EXPECT_EQ(ts.get().kind, t.second);
        ts.ignore();
    }
}

TEST_F(ParserTest, Primary) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"12.345;", 12.345},
        {"(1+2*3);", 7},
        {"1+2*3;", 1},
        {"((3+4)/2)*5;", 3.5},
        {"12 34;", 12},
        {"(8);", 8}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.primary(), t.second);
    }
}

TEST_F(ParserTest, PrimaryError) {
    std::vector<std::string> input = {"+2-3;", "(1+2;"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.primary(), Parser_error);
    }
}
