#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
    string first_name;
    string last_name;
    string telephone;
    string email;
};

const vector<int> column_width{10, 10, 15, 20};

void print_line();
void print_row(const vector<string>& row);
void print_table(const vector<Contact>& contacts);

int main() {
    vector<Contact> contacts{
        {"Alice", "Smith", "12345678", "alice@foxmail.com"},
        {"Bob", "Jones", "23456789", "bob@gmail.com"},
        {"Cindy", "Williams", "34567890", "cindy@sina.com"},
        {"Dale", "Brown", "45678901", "dale@hotmail.com"},
        {"Eric", "Taylor", "56789012", "eric@yahoo.com"},
        {"Frank", "Wilson", "67890123", "frank@sohu.com"},
        {"Grace", "Thomas", "78901234", "grace@qq.com"},
        {"Helen", "Johnson", "89012345", "helen@163.com"},
    };
    print_table(contacts);
    return 0;
}

void print_line() {
    for (int w : column_width)
        cout << '+' << string(w, '-');
    cout << '+' << endl;
}

void print_row(const vector<string>& row) {
    for (int i = 0; i < row.size(); ++i)
        cout << '|' << setw(column_width[i]) << row[i];
    cout << '|' << endl;
}

void print_table(const vector<Contact>& contacts) {
    cout << left;
    print_line();
    print_row({"first_name", "last_name", "telephone", "email"});
    print_line();
    for (const Contact& c : contacts)
        print_row({c.first_name, c.last_name, c.telephone, c.email});
    print_line();
}
