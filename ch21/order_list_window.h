#pragma once

#include <vector>

#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

#include "order.h"
#include "order_edit_window.h"
#include "order_list_table.h"

// A window to display and edit a list of orders, and save and load to/from a file.
class Order_list_window : public Fl_Window {
public:
    Order_list_window(int w, int h, const char* title = nullptr);
    ~Order_list_window() override;

    void load_file();
    void save_file();

private:
    void add_order();
    void edit_order(int i);
    void update_order();

    // widgets
    Order_list_table* order_table_;
    Fl_Box* total_value_;
    Order_edit_window* edit_window_;

    // data
    std::vector<Order> orders_;
};
