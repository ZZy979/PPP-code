#include <iostream>

using namespace std;

int main() {
    double mile = 0;
    cout << "Please enter the number of miles:\n";
    cin >> mile;
    double km = mile * 1.609;
    cout << mile << " miles = " << km << " kilometres\n";
    return 0;
}
