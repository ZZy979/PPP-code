#include <iostream>

#include "doubly_linked_list_v4.h"
#include "high.h"

using namespace std;

// Find and print the element with the highest value in a linked list.
int main() {
    list<int> lst;
    for (int x; cin >> x;) lst.push_front(x);

    auto p = high(lst.begin(), lst.end());
    if (p == lst.end())     // did we reach the end?
        cout << "The list is empty";
    else
        cout << "the highest value is " << *p << '\n';
    return 0;
}
