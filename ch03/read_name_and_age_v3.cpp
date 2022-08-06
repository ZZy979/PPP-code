#include <iostream>
#include <string>

using namespace std;

// read name and age (3nd version)
int main() {
    cout << "Please enter your first name and age\n";
    string first_name = "???";  // string variable ("???" means "don't know the name")
    double age = -1;            // double variable (-1 means "don't know the age")
    cin >> first_name >> age;   // read a string followed by a double
    cout << "Hello, " << first_name << " (age " << age * 12 << " months)\n";
    return 0;
}
