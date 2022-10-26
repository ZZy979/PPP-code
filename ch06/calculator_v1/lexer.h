#pragma once

#include <istream>
#include <stdexcept>

class Token {
public:
    char kind;      // what kind of token
    double value;   // for numbers: a value
};

extern const char number;   // t.kind == number means that t is a number Token

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
