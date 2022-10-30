#include <iostream>

#include "lexer.h"
#include "parser.h"

using namespace std;

const string prompt = "> ";     // prompt user input
const string result = "= ";     // used to indicate that what follows is a result

/*
 * 简单计算器v2，支持+,-,*,/,()运算
 * 输入";"打印结果，输入"q"退出
 */
int main() {
    try {
        Token_stream ts(cin);
        Parser parser(ts);
        while (cin) {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                break;
            ts.putback(t);
            cout << result << parser.expression() << endl;
        }
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
