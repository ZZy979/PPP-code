#include <iostream>

#include "lexer.h"
#include "parser.h"

using namespace std;

/*
 * 简单计算器v2，支持+,-,*,/,()运算
 * 输入";"打印结果，输入"q"退出
 */
int main() {
    try {
        Token_stream ts(cin);
        Parser parser(ts);
        while (cin) {
            cout << "> ";
            Token t = ts.get();
            while (t.kind == ';')
                t = ts.get();   // eat ';'
            if (t.kind == 'q')  // 'q' for "quit"
                break;
            ts.putback(t);
            cout << "= " << parser.expression() << endl;
        }
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
