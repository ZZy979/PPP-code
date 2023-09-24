#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

#include "order.h"

using namespace std;

// Read order data from two file, sort by customer name, merge two order lists and write to another file.
// Compute the total value of the orders.
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " input_file1 input_file2 output_file\n";
        return 0;
    }

    ifstream ifs1(argv[1]), ifs2(argv[2]);
    istream_iterator<Order> iit1(ifs1), iit2(ifs2), eos;
    vector<Order> vo(iit1, eos);
    list<Order> lo(iit2, eos);

    auto less_by_customer_name = [](const Order& a, const Order& b) { return a.customer_name < b.customer_name; };
    sort(vo.begin(), vo.end(), less_by_customer_name);
    lo.sort(less_by_customer_name);

    ofstream ofs(argv[3]);
    ostream_iterator<Order> oit(ofs, "\n");
    merge(vo.begin(), vo.end(), lo.begin(), lo.end(), oit, less_by_customer_name);

    double total_value = get_total_value(vo.begin(), vo.end()) + get_total_value(lo.begin(), lo.end());
    ofs << "\nTotal value of orders: " << total_value << endl;
    return 0;
}
