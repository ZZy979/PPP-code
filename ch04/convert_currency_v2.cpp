#include <iostream>

using namespace std;

// converts yen, euros, pounds, yuan and kroner into dollars
// a suffix 'j', 'u', 'p', 'y' or 'k' indicates the unit of the input
// any other suffix is an error
int main() {
    // conversion rates on 2022-8-26
    const double yen_per_dollar = 136.714;
    const double euros_per_dollar = 1.0035;
    const double pounds_per_dollar = 0.8465;
    const double yuan_per_dollar = 6.8492;
    const double kroner_per_dollar = 9.6982;
    double amount = 1;
    char unit = ' ';
    cout << "Please enter amount of currency followed by a unit (j, u, p, y or k):\n";
    cin >> amount >> unit;

    switch (unit) {
        case 'j':
            cout << amount << " yen == " << amount / yen_per_dollar << " dollars\n";
            break;
        case 'u':
            cout << amount << " euros == " << amount / euros_per_dollar << " dollars\n";
            break;
        case 'p':
            cout << amount << " pounds == " << amount / pounds_per_dollar << " dollars\n";
            break;
        case 'y':
            cout << amount << " yuan == " << amount / yuan_per_dollar << " dollars\n";
            break;
        case 'k':
            cout << amount << " kroner == " << amount / kroner_per_dollar << " dollars\n";
            break;
        default:
            cout << "Sorry, I don't know a unit called '" << unit << "'\n";
            break;
    }
    return 0;
}
