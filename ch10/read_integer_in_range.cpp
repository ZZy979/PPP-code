#include <iostream>
#include <stdexcept>

#include "get_int.h"

using namespace std;

int main() {
    try {
        int strength = get_int(cin, 1, 10, "Enter strength", "Not in range, try again");
        cout << "strength: " << strength << endl;

        int altitude = get_int(cin, 0, 50000,
                "Please enter altitude in feet",
                "Not in range, please try again");
        cout << "altitude: " << altitude << "f above sea level\n";
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
