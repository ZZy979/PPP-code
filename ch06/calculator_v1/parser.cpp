#include "parser.h"

Parser::Parser(Token_stream& ts) :ts(ts) {
}

double Parser::expression() {
    double left = term();   // read and evaluate a Term
    Token op = ts.get();    // get next Token from Token stream
    while (op.kind == '+' || op.kind == '-') {
        if (op.kind == '+')
            left += term();     // evaluate Term and add
        else
            left -= term();     // evaluate Term and subtract
        op = ts.get();
    }
    ts.putback(op);     // put op back into Token stream
    return left;        // finally: no more + or -, return the answer
}

double Parser::term() {
    double left = primary();
    Token op = ts.get();
    while (op.kind == '*' || op.kind == '/') {
        if (op.kind == '*')
            left *= primary();
        else {
            double d = primary();
            if (d == 0)
                throw Parser_error("divided by zero");
            left /= d;
        }
        op = ts.get();
    }
    ts.putback(op);
    return left;
}

double Parser::primary() {
    Token t = ts.get();
    if (t.kind == '(') {
        // handle "(" Expression ")"
        double d = expression();
        if (ts.get().kind != ')')
            throw Parser_error("')' expected");
        return d;
    }
    else if (t.kind == number)
        return t.value;
    else
        throw Parser_error("primary expected");
}
