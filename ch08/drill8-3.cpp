#include <iostream>

using namespace std;

namespace X {
int var;
void print() { cout << var << endl; }
}

namespace Y {
int var;
void print() { cout << var << endl; }
}

namespace Z {
int var;
void print() { cout << var << endl; }
}

int main() {
    X::var = 7;
    X::print();     // print X's var
    using namespace Y;
    var = 9;
    print();        // print Y's var
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();    // print Z's var
    }
    print();        // print Y's var
    X::print();     // print X's var
    return 0;
}
