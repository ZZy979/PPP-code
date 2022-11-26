#include <gtest/gtest.h>

#include <sstream>
#include <vector>
#include <string>

#include "lexer.h"
#include "parser.h"

class CalculatorV2ParserTest : public ::testing::Test {
protected:
    CalculatorV2ParserTest() :ts(iss), parser(ts) {}

    std::istringstream iss;
    Token_stream ts;
    Parser parser;
};

TEST_F(CalculatorV2ParserTest, Statement) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"let a = 9/(5-3);", 4.5},
        {"let b=(a+2.5)*(8-5);", 21},
        {"a+b*2;", 46.5}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.statement(), t.second);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, Declaration) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"a = 1;", 1},
        {"b=(a+3)*2;", 8}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.declaration(), t.second);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, DeclarationParserError) {
    std::vector<std::string> input = {"let a = 1;", "2 = 2;", "a+1"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.declaration(), Parser_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, InvalidVariableName) {
    iss.str("a$ = 1;");
    EXPECT_THROW(parser.declaration(), Lexer_error);
}

TEST_F(CalculatorV2ParserTest, VariableRedefiniton) {
    iss.str("a = 1;");
    parser.declaration();

    iss.str("a = 2;");
    EXPECT_THROW(parser.declaration(), Parser_error);
}

TEST_F(CalculatorV2ParserTest, Expression) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"8;", 8},
        {"1+2*3;", 7},
        {"1-2*3+4;", -1},
        {"1-34/50;", 0.32},
        {"42+(11-4)/8-9*(32.5+24.7);", -471.925},
        {"+2-3;", -1},
        {"-(6-5)/2;", -0.5},
        {"--1++2;", 3},
        {"6.7%3.3+(2*17-0.7)*3;", 100},
        {"pow(1+tan(pi/3),2)-2*sqrt(3);", 4}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_NEAR(parser.expression(), t.second, 1e-6);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, ExpressionLexerError) {
    std::vector<std::string> input = {
        "!+2", "'a';", "1@2", "[2.5]",
        "!@#$%^&*()~:;"
    };
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.expression(), Lexer_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, ExpressionParserError) {
    std::vector<std::string> input = {
        ";;;", "(1+3;", "(1+);", "();", "1+;", "1++;", "1/0;",
        "q", "1+q"
    };
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.expression(), Parser_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, Term) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"3.14;", 3.14},
        {"2*3/4;", 1.5},
        {"(1+2)*(3-4*5)/8;", -6.375},
        {"5.8%2.3;", 1.2},
        {"-5.8%2.3;", -1.2},
        {"5.8%-2.3;", 1.2},
        {"-5.8%(-2.3);", -1.2}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.term(), t.second);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, TermDevidedByZero) {
    std::vector<std::string> input = {"1/0;", "2%0;", "3/(8-4*2);"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.term(), Parser_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, TermPutBack) {
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

TEST_F(CalculatorV2ParserTest, Primary) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"12.345;", 12.345},
        {"(1+2*3);", 7},
        {"1+2*3;", 1},
        {"((3+4)/2)*5;", 3.5},
        {"12 34;", 12},
        {"(8);", 8},
        {"1+;", 1},
        {"1+q", 1}
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_DOUBLE_EQ(parser.primary(), t.second);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, PrimaryError) {
    std::vector<std::string> input = {";;;", "(1+3;", "(1+);", "();", "q"};
    for (const auto& s : input) {
        iss.str(s);
        EXPECT_THROW(parser.primary(), Parser_error) << "input: " << s;
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, UndefinedVariable) {
    iss.str("a");
    EXPECT_THROW(parser.primary(), Variable_error);
}

TEST_F(CalculatorV2ParserTest, PredefinedNames) {
    std::vector<std::pair<std::string, double>> test_cases = {
        {"pi;", 3.14159265358},
        {"e;", 2.718281828},
    };
    for (const auto& t : test_cases) {
        iss.str(t.first);
        EXPECT_NEAR(parser.primary(), t.second, 1e-6);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, Function) {
    struct Test_case {
        std::string func_name;
        std::string input;
        double expected;
    };
    std::vector<Test_case> test_cases = {
        {"sin", "(pi/6);", 0.5},
        {"sqrt", "(6.25);", 2.5},
        {"pow", "(2, 3);", 8},
        {"pow", "(sqrt(10), 4)", 100},
        {"exp", "(log(444))", 444}
    };
    for (const auto& t : test_cases) {
        iss.str(t.input);
        EXPECT_NEAR(parser.function(t.func_name), t.expected, 1e-6);
        ts.ignore();
    }
}

TEST_F(CalculatorV2ParserTest, FunctionParserError) {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        {"sin", ";"},
        {"sin", "3.5;"},
        {"sin", "();"},
        {"sin", "(3.14;"},
        {"sin", "(2,3);"},
        {"pow", "(4);"},
        {"pow", "(2,);"},
        {"pow", "(3,2;"},
        {"pow", "(3 2);"},
        {"pow", "(5,6,7);"}
    };
    for (const auto& t : test_cases) {
        iss.str(t.second);
        EXPECT_THROW(parser.function(t.first), Parser_error);
        ts.ignore();
    }
}
