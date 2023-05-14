#include <iostream>
#include <string>

using namespace std;

// read individual characters until an exclamation mark (!) is entered
int main() {
    char* a = new char[20]{'\0'};
    char c;
    for (int i = 0; (c = cin.get()) != '!'; a[i++] = c);
    cout << a << endl;
    delete[] a;

    string s;
    while ((c = cin.get()) != '!')
        s += c;
    cout << s << endl;
    return 0;
}
