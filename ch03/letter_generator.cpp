#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter the name of the person you want to write to\n";
    string first_name;
    cin >> first_name;

    cout << "Enter the name of another friend\n";
    string friend_name;
    cin >> friend_name;

    cout << "If the friend is male, enter an 'm', or enter an 'f'\n";
    char friend_sex = 0;
    cin >> friend_sex;

    cout << "Please enter the age of the person you want to write to\n";
    int age = 0;
    cin >> age;
    if (age <= 0 || age >= 110)
        cerr << "You're kidding!\n";

    cout << "Dear " << first_name << ",\n";
    cout << "  How are you? I am fine. I miss you.\n";
    cout << "  Have you seen " << friend_name << " lately? ";
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    else
        cout << "If you see " << friend_name << " please ask her to call me.\n";

    if (age < 12)
        cout << "  Next year you will be " << age + 1 << ".\n";
    else if (age == 17)
        cout << "  Next year you will be able to vote.\n";
    else if (age > 70)
        cout << "  I hope you are enjoying retirement.\n";

    cout << "Yours sincerely,\n\n\nZZy";
    return 0;
}
