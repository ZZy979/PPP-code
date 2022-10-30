#pragma once

#include <istream>
#include <stdexcept>

class Token {
public:
    char kind;      // what kind of token
    double value;   // for numbers: a value
};

const char number = '8';    // t.kind == number means that t is a number Token
const char quit = 'q';      // t.kind == quit means that t is a quit Token
const char print = ';';     // t.kind == print means that t is a print Token

class Token_stream {
public:
    explicit Token_stream(std::istream& is);
    Token get();
    void putback(Token t);
    void ignore();

private:
    std::istream& is;   // input stream to read from
    bool full;          // is there a Token in the buffer?
    Token buffer;       // here is where we keep a Token put back using putback()
};

class Lexer_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
