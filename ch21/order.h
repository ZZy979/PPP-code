#pragma once

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct Purchase {
    std::string product_name;
    double unit_price;
    int count;
};

struct Order {
    std::string customer_name;
    std::string address;
    std::string phone_number;
    std::vector<Purchase> purchase;
};

std::istream& operator>>(std::istream& is, Purchase& p);
std::istream& operator>>(std::istream& is, Order& o);
std::ostream& operator<<(std::ostream& os, const Purchase& p);
std::ostream& operator<<(std::ostream& os, const Order& o);

void end_of_loop(std::istream& ist, char terminator, const std::string& message);
double get_purchase_value(const Purchase& p);
double get_order_value(const Order& o);

template<class Iter>
double get_total_value(Iter first, Iter last) {
    return std::accumulate(first, last, 0.0, [](double v, const Order& o) { return v + get_order_value(o); });
}
