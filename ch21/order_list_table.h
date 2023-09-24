#pragma once

#include <string>
#include <vector>

#include <FL/Fl_Table.H>

#include "order.h"

// A table of orders.
class Order_list_table : public Fl_Table {
public:
    Order_list_table(int x, int y, int w, int h, std::vector<Order>& orders);

    void update_content();

protected:
    void draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H) override;

private:
    static const std::vector<std::string> COLUMN_NAMES;
    static const std::vector<int> COLUMN_WIDTH;

    std::vector<Order>& orders_;
};

std::string get_column_text(const Order& o, int c);
