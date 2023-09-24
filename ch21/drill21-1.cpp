#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct Item {
    string name;
    int iid;
    double value;
};

istream& operator>>(istream& is, Item& item) {
    Item tmp;
    if (is >> tmp.name >> tmp.iid >> tmp.value)
        item = tmp;
    return is;
}

ostream& operator<<(ostream& os, const Item& item) {
    return os << left << setw(15) << item.name << ' '
            << right << setw(5) << item.iid << ' '
            << setw(10) << item.value;
}

bool less_by_name(const Item& a, const Item& b) { return a.name < b.name; }
bool less_by_iid(const Item& a, const Item& b) { return a.iid < b.iid; }
bool greater_by_value(const Item& a, const Item& b) { return a.value > b.value; }

struct Equal_by_name {
    bool operator()(const Item& item) const { return item.name == name; }
    const string& name;
};

struct Equal_by_iid {
    bool operator()(const Item& item) const { return item.iid == iid; }
    int iid;
};

template<class T, class Pred>
void sort(vector<T>& v, Pred p) {
    sort(v.begin(), v.end(), p);
}

template<class T, class Pred>
void sort(list<T>& l, Pred p) {
    l.sort(p);
}

template<class C>
void test(const string& input_file) {
    ifstream ifs(input_file);
    if (!ifs) {
        cerr << "can't open input file " << input_file;
        return;
    }

    istream_iterator<Item> iit(ifs), eos;
    C c(iit, eos);

    ostream_iterator<Item> oit(cout, "\n");
    cout << "Initial items:\n";
    copy(c.begin(), c.end(), oit);

    sort(c, less_by_name);
    cout << "\nSort by name:\n";
    copy(c.begin(), c.end(), oit);

    sort(c, less_by_iid);
    cout << "\nSort by iid:\n";
    copy(c.begin(), c.end(), oit);

    sort(c, greater_by_value);
    cout << "\nSort by value in reverse order:\n";
    copy(c.begin(), c.end(), oit);

    c.push_back({"horse shoe", 99, 12.34});
    c.push_back({"Canon S400", 9988, 499.95});
    cout << "\nInsert two new items:\n";
    copy(c.begin(), c.end(), oit);

    c.erase(remove_if(c.begin(), c.end(), Equal_by_name{"banana"}), c.end());
    c.erase(remove_if(c.begin(), c.end(), Equal_by_name{"cake"}), c.end());
    cout << "\nRemove two items by name:\n";
    copy(c.begin(), c.end(), oit);

    c.erase(remove_if(c.begin(), c.end(), Equal_by_iid{9988}), c.end());
    c.erase(remove_if(c.begin(), c.end(), Equal_by_iid{705}), c.end());
    cout << "\nRemove two items by iid:\n";
    copy(c.begin(), c.end(), oit);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file\n";
        return 0;
    }

    cout << "vector test\n";
    test<vector<Item>>(argv[1]);

    cout << "\nlist test\n";
    test<list<Item>>(argv[1]);
    return 0;
}
