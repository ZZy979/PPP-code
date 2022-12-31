#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void read_name(vector<string>& name, int n);
void read_age(vector<double>& age, int n);
void print_name_age(const vector<string>& name, const vector<double>& age);
void sort_by_name(vector<string>& name, vector<double>& age);

// read names and ages of people, sort by name and print (name, age) pairs
int main() {
    cout << "Please enter the number of people:\n";
    int n;
    cin >> n;

    cout << "Please enter their names:\n";
    vector<string> name;
    read_name(name, n);

    cout << "Please enter their ages:\n";
    vector<double> age;
    read_age(age, n);

    cout << "Before sorting:\n";
    print_name_age(name, age);

    sort_by_name(name, age);
    cout << "After sorting:\n";
    print_name_age(name, age);
    return 0;
}

void read_name(vector<string>& name, int n) {
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        name.push_back(s);
    }
}

void read_age(vector<double>& age, int n) {
    double a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        age.push_back(a);
    }
}

void print_name_age(const vector<string>& name, const vector<double>& age) {
    for (int i = 0; i < name.size(); ++i)
        cout << '(' << name[i] << ',' << age[i] << ')' << endl;
}

void sort_by_name(vector<string>& name, vector<double>& age) {
    vector<string> unsorted_name = name;
    vector<double> unsorted_age = age;
    sort(name.begin(), name.end());
    for (int i = 0; i < age.size(); ++i) {
        int j = find(unsorted_name.begin(), unsorted_name.end(), name[i]) - unsorted_name.begin();
        age[i] = unsorted_age[j];
    }
}
