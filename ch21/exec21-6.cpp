#include <iomanip>
#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Fruit {
    string name;
    int count;
    double unit_price;
};

struct Fruit_order {
    bool operator()(const Fruit& a, const Fruit& b) const {
        return a.name < b.name;
    }
};

struct Fruit_pointer_order {
    bool operator()(Fruit* a, Fruit* b) const {
        return a->name < b->name;
    }
};

ostream& operator<<(ostream& os, const Fruit& fruit) {
    return os << left << setw(15) << fruit.name
            << right << setw(5) << fruit.count
            << setw(10) << fruit.unit_price;
}

int main() {
    set<Fruit, Fruit_order> inventory;
    set<Fruit*, Fruit_pointer_order> inventory2;
    for (Fruit fruit; cin >> fruit.name >> fruit.count >> fruit.unit_price;) {
        inventory.insert(fruit);
        inventory2.insert(new Fruit(fruit));
    }

    cout << "set<Fruit>:\n";
    for (const Fruit& fruit : inventory)
        cout << fruit << endl;

    cout << "\nset<Fruit*>:\n";
    for (Fruit* fruit : inventory2)
        cout << *fruit << endl;

    for (Fruit* fruit : inventory2)
        delete fruit;
    return 0;
}
