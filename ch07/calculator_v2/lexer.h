#pragma once

#include <istream>
#include <vector>
#include <string>
#include <stdexcept>

class Token {
public:
    char kind;          // what kind of token
    double value;       // for numbers: a value
    std::string name;   // for identifiers: variable name

    Token(char kind) :kind(kind) {}
    Token(char kind, double value) :kind(kind), value(value) {}
    Token(char kind, const std::string& name) :kind(kind), name(name) {}
};

const char number = '8';            // number token
const char name = 'a';              // name token
const char let = 'L';               // variable declaration token
const char constant = 'C';          // constant declaration token
const std::string var_declkey = "let";      // variable declaration keyword
const std::string const_declkey = "const";  // constant declaration keyword
const char help = 'h';              // help token
const char quit = 'q';              // quit token
const char print = ';';             // print token

class Token_stream {
public:
    explicit Token_stream(std::istream& is);
    Token get();
    void putback(Token t);
    void ignore();
    void ignore(char c);

private:
    std::istream& is;   // input stream to read from
    std::vector<Token> buffer;  // here is where we keep Tokens put back using putback()
};

class Lexer_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};
