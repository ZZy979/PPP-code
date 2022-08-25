#include <iostream>

using namespace std;

// convert from inches to centimeters or centimeters to inches
// a suffix 'i' or 'c' indicates the unit of the input
// any other suffix is an error
int main() {
    const double cm_per_inch = 2.54;    // number of centimeters in an inch
    double length = 1;                  // length in inches or centimeters
    char unit = ' ';                    // a space is not a unit
    cout << "Please enter a length followed by a unit (c or i):\n";
    cin >> length >> unit;

    if (unit == 'i')
        cout << length << " in == " << length * cm_per_inch << " cm\n";
    else if (unit == 'c')
        cout << length << " cm == " << length / cm_per_inch << " in\n";
    else
        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
    return 0;
}
