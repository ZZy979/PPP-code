#include "parser.h"

Parser::Parser(Token_stream& ts) :ts(ts) {
}

double Parser::expression() {
    double left = term();   // read and evaluate a Term
    Token op = ts.get();    // get next Token from Token stream
    while (true) {
        switch (op.kind) {
            case '+':
                left += term();     // evaluate Term and add
                op = ts.get();
                break;
            case '-':
                left -= term();     // evaluate Term and subtract
                op = ts.get();
                break;
            default:
                ts.putback(op);     // put op back into Token stream
                return left;        // finally: no more + or -, return the answer
        }
    }
}

double Parser::term() {
    double left = primary();
    Token op = ts.get();
    while (true) {
        switch (op.kind) {
            case '*':
                left *= primary();
                op = ts.get();
                break;
            case '/': {
                double d = primary();
                if (d == 0)
                    throw Parser_error("divided by zero");
                left /= d;
                op = ts.get();
                break;
            }
            default:
                ts.putback(op);
                return left;
        }
    }
}

double Parser::primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(': {     // handle "(" Expression ")"
            double d = expression();
            if (ts.get().kind != ')')
                throw Parser_error("')' expected");
            return d;
        }
        case number:
            return t.value;
        case '+':
            return primary();
        case '-':
            return -primary();
        default:
            throw Parser_error("primary expected");
    }
}
