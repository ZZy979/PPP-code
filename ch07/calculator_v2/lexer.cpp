#include "lexer.h"

#include <algorithm>

// make a Token_stream that reads from istream
Token_stream::Token_stream(std::istream& is) :is(is) {}

// get a Token
Token Token_stream::get() {
    if (!buffer.empty()) {  // do we already have a Token ready?
        // remove Token from buffer
        Token t = buffer.back();
        buffer.pop_back();
        return t;
    }

    char ch;
    is >> ch;   // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        case help:
        case print:
        case quit:
        case '(': case ')': case '+': case '-': case '*': case '/': case '%': case '=': case ',':
            return Token(ch);   // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9': {
            is.putback(ch);         // put digit back into the input stream
            double val;
            is >> val;              // read a floating-point number
            return Token(number, val);
        }
        default:
            if (std::isalpha(ch)) {
                std::string s;
                s += ch;
                while (is.get(ch) && std::isalnum(ch))
                    s += ch;
                is.putback(ch);
                if (s == var_declkey)
                    return Token(let);
                else if (s == const_declkey)
                    return Token(constant);
                return Token(name, s);
            }
            throw Lexer_error("Bad token");
    }
}

// put a Token back
void Token_stream::putback(Token t) {
    buffer.push_back(t);
}

// discard Token in buffer
void Token_stream::ignore() {
    buffer.clear();
}

// discard characters up to and including c
void Token_stream::ignore(char c) {
    // first look in buffer
    auto it = std::find_if(buffer.begin(), buffer.end(), [c](Token t) { return t.kind == c; });
    if (it != buffer.end()) {
        buffer.erase(it, buffer.end());
        return;
    }

    // now search input
    char ch;
    while (is >> ch && ch != c)
        ;
}
