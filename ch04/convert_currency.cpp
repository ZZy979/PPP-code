#include <iostream>

using namespace std;

// converts yen, euros, and pounds into dollars
// a suffix 'j', 'u' or 'p' indicates the unit of the input
// any other suffix is an error
int main() {
    // conversion rates on 2022-8-26
    const double yen_per_dollar = 136.714;
    const double euros_per_dollar = 1.0035;
    const double pounds_per_dollar = 0.8465;
    double amount = 1;
    char unit = ' ';
    cout << "Please enter amount of currency followed by a unit (j, u or p):\n";
    cin >> amount >> unit;

    if (unit == 'j')
        cout << amount << " yen == " << amount / yen_per_dollar << " dollars\n";
    else if (unit == 'u')
        cout << amount << " euros == " << amount / euros_per_dollar << " dollars\n";
    else if (unit == 'p')
        cout << amount << " pounds == " << amount / pounds_per_dollar << " dollars\n";
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
    return 0;
}
