#include <iostream>
#include <stdexcept>

using namespace std;

// 简单计算器v0，支持+,-,*,/运算
// bug：*,/和+,-的优先级相同
int main() {
    try {
        cout << "Please enter expression (we can handle +, -, * and /)\n";
        cout << "add ; to end expression (e.g., 1+2*3;):";
        int lval = 0, rval;
        char op;
        cin >> lval;  // read leftmost operand
        if (!cin)
            throw invalid_argument("no first operand");
        while (cin >> op) {     // read operator and right-hand operand repeatedly
            if (op != ';')
                cin >> rval;
            if (!cin)
                throw invalid_argument("no second operand");
            switch (op) {
                case '+':
                    lval += rval;
                    break;
                case '-':
                    lval -= rval;
                    break;
                case '*':
                    lval *= rval;
                    break;
                case '/':
                    lval /= rval;
                    break;
                default:    // not another operator: print result
                    cout << "Result: " << lval << '\n';
                    return 0;
            }
        }
        throw invalid_argument("bad expression");
    }
    catch (invalid_argument& e) {
        cerr << "error: " << e.what() << '\n';
        return 0;
    }
}
