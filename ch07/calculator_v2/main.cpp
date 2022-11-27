#include <iostream>

#include "lexer.h"
#include "parser.h"

/*
    Simple calculator

    This program implements a basic expression calculator.
    Input from cin; output to cout.

    The grammar for input is:

    Calculation:
        Statement
        Calculation Statement
        Help
        Print
        Quit
    Statement:
        Declaration
        Assignment
        Expression
    Declaration:
        "let" Name "=" Expression
        "const" Name "=" Expression
    Assignment:
        Name "=" Expression
    Help:
        "h"
    Print:
        ";"
    Quit:
        "q"
    Expression:
        Term
        Expression "+" Term
        Expression "-" Term
    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary
    Primary:
        Number
        Name
        Function
        "(" Expression ")"
        "+" Primary
        "-" Primary
    Number:
        floating-point-literal
    Function:
        Name "(" Expression ")"
        Name "(" Expression "," Expression ")"
    Name:
        identifier

    Input comes from cin through the Token_stream called ts.
*/

using namespace std;

const string prompt = "> ";     // prompt user input
const string result = "= ";     // used to indicate that what follows is a result

Token_stream ts(cin);
Parser parser(ts);

void calculate();
void clean_up_mess();
void show_help();

int main() {
    cout << "Simple calculator.\nEnter 'h' to show help.\n";
    calculate();
    return 0;
}

// expression calculation loop
void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == help)
                show_help();
            else if (t.kind == quit)
                break;
            else {
                ts.putback(t);
                cout << result << parser.statement() << endl;
            }
        }
        catch (exception& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}

void clean_up_mess() {
    ts.ignore(print);
}

void show_help() {
    cout << "Enter expressions of floating-point numbers, terminating with ';'.\n"
            "Available operators:\n"
            "    +, -, *, /, %, ()\n"
            "Available functions:\n"
            "    sin(x), cos(x), tan(x), exp(x), log(x), sqrt(x), fabs(x), pow(x, y)\n"
            "Variable declaration:\n"
            "    let name = expression;\n"
            "Constant declaration:\n"
            "    const name = expression;\n"
            "Assignment:\n"
            "    name = expression;\n"
            "Predefined constants:\n"
            "    pi, e\n"
            "Show help:\n"
            "    h\n"
            "Quit:\n"
            "    q\n";
}
