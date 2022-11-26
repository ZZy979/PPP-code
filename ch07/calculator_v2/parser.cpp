#include "parser.h"

#include <cmath>

#include "function.h"

Parser::Parser(Token_stream& ts) :ts(ts) {
    var_table.define_name("pi", 4 * atan(1));
    var_table.define_name("e", exp(1));
}

double Parser::statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

double Parser::declaration() {
    // assume we have seen "let"
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
    Token t = ts.get();
    if (t.kind != name)
        throw Parser_error("name expected in declaration");
    std::string var_name = t.name;

    t = ts.get();
    if (t.kind != '=')
        throw Parser_error("'=' missing in declaration of " + var_name);

    double d = expression();
    var_table.define_name(var_name, d);
    return d;
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
            case '%': {
                double d = primary();
                if (d == 0)
                    throw Parser_error("divided by zero");
                left = fmod(left, d);
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
        case name:
            return is_function_name(t.name) ? function(t.name) : var_table.get_value(t.name);
        case '+':
            return primary();
        case '-':
            return -primary();
        default:
            throw Parser_error("primary expected");
    }
}

double Parser::function(const std::string& func_name) {
    // assume we have seen function name
    // handle: (expression[, expression])
    Token t = ts.get();
    if (t.kind != '(')
        throw Parser_error("'(' expected");

    bool is_one_argument = is_one_argument_function(func_name);
    double x = expression(), res;
    if ((t = ts.get()).kind == ',') {
        // two-argument function
        if (is_one_argument)
            throw Parser_error(func_name + " expects 1 argument, but 2 given");
        double y = expression();
        res = calculate_function(func_name, x, y);
        t = ts.get();
    } else {
        // one-argument function
        if (!is_one_argument)
            throw Parser_error(func_name + " expects 2 argument, but 1 given");
        res = calculate_function(func_name, x);
    }

    if (t.kind != ')')
        throw Parser_error("')' expected");
    return res;
}
