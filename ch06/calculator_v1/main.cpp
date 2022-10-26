#include <iostream>

#include "lexer.h"
#include "parser.h"

using namespace std;

/*
 * 简单计算器v1，支持+,-,*,/,()运算
 * 输入";"打印结果，输入"q"退出
 *
 * 问题：不支持负数，不支持取模运算%，"q"的处理位置不正确，没有错误恢复
 */
int main() {
    Token_stream ts(cin);
    Parser parser(ts);
    double val = 0;
    try {
        while (cin) {
            Token t = ts.get();
            if (t.kind == 'q')  // 'q' for "quit"
                break;
            else if (t.kind == ';')     // ';' for "print"
                cout << '=' << val << endl;
            else
                ts.putback(t);
            val = parser.expression();
        }
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
