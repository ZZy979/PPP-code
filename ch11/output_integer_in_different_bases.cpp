#include <iostream>

using namespace std;

// Output your birth year and age in decimal, hexadecimal, and octal form.
int main() {
    int birth_year = 1997, age = 25;
    cout << "base\t\tbirth year\tage\n"
            << "decimal\t\t" << birth_year << "\t\t" << age << '\n'
            << hex << "hexadecimal\t" << birth_year << "\t\t\t" << age << '\n'
            << oct << "octal\t\t" << birth_year << "\t\t" << age << '\n';
    return 0;
}
