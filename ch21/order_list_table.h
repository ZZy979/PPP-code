#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <FL/Fl_Table.H>

#include "order.h"
#include "order_edit_window.h"

// A table of orders, supports editing and filtering.
class Order_list_table : public Fl_Table {
public:
    Order_list_table(int x, int y, int w, int h);

    std::vector<Order>& orders() { return orders_; }
    std::vector<std::reference_wrapper<Order>>& filtered_orders() { return filtered_orders_; }

    void add_order();
    void edit_order();
    void filter_by_customer_name(const std::string& name);
    void update_content();

protected:
    void draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H) override;

private:
    void set_table_size();
    void update_order();

    static const std::vector<std::string> COLUMN_NAMES;
    static const std::vector<int> COLUMN_WIDTH;

    // widgets
    std::unique_ptr<Order_edit_window> edit_window_;

    // data
    std::vector<Order> orders_;  // original order data
    std::vector<std::reference_wrapper<Order>> filtered_orders_;  // filtered order data (for displaying)
    std::function<bool(const Order&)> filter_;
};

std::string get_column_text(const Order& o, int c);
