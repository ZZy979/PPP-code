#include <iostream>

using namespace std;

int main() {
    int penny, nickel, dime, quarter, half_dollar, dollar;
    double total;
    cout << "How many pennies do you have?\n";
    cin >> penny;
    cout << "How many nickels do you have?\n";
    cin >> nickel;
    cout << "How many dimes do you have?\n";
    cin >> dime;
    cout << "How many quarters do you have?\n";
    cin >> quarter;
    cout << "How many half_dollars do you have?\n";
    cin >> half_dollar;
    cout << "How many dollars do you have?\n";
    cin >> dollar;

    cout << "You have " << penny << ((penny > 1) ? " pennies." : " penny.") << endl;
    cout << "You have " << nickel << " nickel" << ((nickel > 1) ? "s." : ".") << endl;
    cout << "You have " << dime << " dime" << ((dime > 1) ? "s." : ".") << endl;
    cout << "You have " << quarter << " quarter" << ((quarter > 1) ? "s." : ".") << endl;
    cout << "You have " << half_dollar << " half dollar" << ((half_dollar > 1) ? "s." : ".") << endl;
    cout << "You have " << dollar << " dollar" << ((dollar > 1) ? "s." : ".") << endl;
    total = (penny + nickel * 5 + dime * 10 + quarter * 25 + half_dollar * 50 + dollar * 100) / 100.0;
    cout << "Total: $" << total << endl;
    return 0;
}
