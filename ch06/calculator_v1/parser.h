#pragma once

#include <stdexcept>

#include "lexer.h"

class Parser {
public:
    explicit Parser(Token_stream& ts);
    double expression();
    double term();
    double primary();

private:
    Token_stream& ts;
};

class Parser_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
