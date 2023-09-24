#pragma once

#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Window.H>

#include "order.h"
#include "purchase_list_table.h"

// A window to edit an order.
class Order_edit_window : public Fl_Window {
public:
    Order_edit_window(int w, int h, const char* title = nullptr);

    void ok_callback(Fl_Callback* cb, void* data) { ok_button_->callback(cb, data); }
    void update_customer_name() { order_.customer_name = customer_name_input_->value(); }
    void update_address() { order_.address = address_input_->value(); }
    void update_phone_number() { order_.phone_number = phone_number_input_->value(); }

    const Order& get_order() const { return order_; }
    void set_order(const Order& o) { order_ = o; fill_order_info(); }

    int index() const { return index_; }
    void set_index(int index) { index_ = index; }

private:
    void fill_order_info();
    void add_purchase();

    // widgets
    Fl_Input* customer_name_input_;
    Fl_Input* address_input_;
    Fl_Input* phone_number_input_;
    Purchase_list_table* purchase_table_;
    Fl_Button* ok_button_;

    // data
    Order order_;
    int index_;
};
