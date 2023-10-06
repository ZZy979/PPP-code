#pragma once

#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>

#include "order_list_table.h"

// A window to display and edit a list of orders, and save and load to/from a file.
class Order_list_window : public Fl_Window {
public:
    Order_list_window(int w, int h, const char* title = nullptr);

    void load_file() const;
    void save_file() const;

    void query_by_customer_name() const;
    void update_total_value() const;

    // widgets
    Fl_Input* customer_name_input_;
    Order_list_table* order_table_;
    Fl_Box* total_value_;
};
