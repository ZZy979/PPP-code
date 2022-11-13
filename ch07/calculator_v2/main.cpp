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
        Print
        Quit
    Statement:
        Declaration
        Expression
    Declaration:
        "let" Name "=" Expression
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
        "(" Expression ")"
        "+" Primary
        "-" Primary
    Number:
        floating-point-literal
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

int main() {
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
            if (t.kind == quit)
                break;
            ts.putback(t);
            cout << result << parser.statement() << endl;
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
