#pragma once

#include <stdexcept>

#include "lexer.h"
#include "variable.h"

class Parser {
public:
    explicit Parser(Token_stream& ts);
    double statement();
    double declaration();
    double expression();
    double term();
    double primary();

private:
    Token_stream& ts;
    Symbol_table var_table;
};

class Parser_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
