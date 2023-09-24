#include "order.h"

#include <iomanip>
#include <stdexcept>

// read a purchase
// format: (product_name unit_price count)
std::istream& operator>>(std::istream& is, Purchase& p) {
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    Purchase tmp;
    char ch2;
    if (!(is >> std::quoted(tmp.product_name) >> tmp.unit_price >> tmp.count >> ch2) || ch2 != ')')
        throw std::runtime_error("bad purchase");
    p = std::move(tmp);
    return is;
}

// read an order
// format: {customer_name address phone_number purchase...}
std::istream& operator>>(std::istream& is, Order& o) {
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }

    Order tmp;
    if (!(is >> std::quoted(tmp.customer_name) >> std::quoted(tmp.address) >> std::quoted(tmp.phone_number)))
        throw std::runtime_error("bas start of order");
    o = std::move(tmp);

    while (true) {
        Purchase p;
        if (!(is >> p)) break;
        o.purchase.push_back(p);
    }
    end_of_loop(is, '}', "bad end of order");
    return is;
}

std::ostream& operator<<(std::ostream& os, const Purchase& p) {
    return os << '(' << std::quoted(p.product_name) << ' ' << p.unit_price << ' ' << p.count << ')';
}

std::ostream& operator<<(std::ostream& os, const Order& o) {
    os << "{ " << std::quoted(o.customer_name) << ' ' << std::quoted(o.address)
            << ' ' << std::quoted(o.phone_number) << ' ';
    for (const Purchase& p : o.purchase)
        os << p << ' ';
    os << '}';
    return os;
}

void end_of_loop(std::istream& ist, char terminator, const std::string& message) {
    if (ist.fail()) {  // use term as terminator and/or separator
        ist.clear();
        char ch;
        if (ist >> ch && ch == terminator) return;  // all is fine
        throw std::runtime_error(message);
    }
}

double get_purchase_value(const Purchase& p) {
    return p.unit_price * p.count;
}

double get_order_value(const Order& o) {
    return std::accumulate(
            o.purchase.begin(), o.purchase.end(), 0.0,
            [](double v, const Purchase& p) { return v + get_purchase_value(p); });
}
