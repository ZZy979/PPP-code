#include "order_edit_window.h"

#include <FL/Fl_Box.H>

Order_edit_window::Order_edit_window(int w, int h, const char* title) :Fl_Window(w, h, title) {
    Fl_Box* header = new Fl_Box(0, 0, w, 40, "Edit order");
    header->labelsize(20);

    customer_name_input_ = new Fl_Input(120, 40, w - 140, 25, "Customer name:");
    customer_name_input_->callback(
            [](Fl_Widget*, void* w) { static_cast<Order_edit_window*>(w)->update_customer_name(); }, this);

    address_input_ = new Fl_Input(120, 75, w - 140, 25, "Address:");
    address_input_->callback(
            [](Fl_Widget*, void* w) { static_cast<Order_edit_window*>(w)->update_address(); }, this);

    phone_number_input_ = new Fl_Input(120, 110, w - 140, 25, "Phone number:");
    phone_number_input_->callback(
            [](Fl_Widget*, void* w) { static_cast<Order_edit_window*>(w)->update_phone_number(); }, this);

    Fl_Button* add_button = new Fl_Button(w - 120, 145, 100, 25, "Add");
    ok_button_ = new Fl_Button(100, h - 50, 150, 30, "OK");
    Fl_Button* cancel_button = new Fl_Button(350, h - 50, 150, 30, "Cancel");
    cancel_button->callback([](Fl_Widget*, void* w) { static_cast<Order_edit_window*>(w)->hide(); }, this);

    // initialize table at last to avoid changing Fl_Group::current()
    purchase_table_ = new Purchase_list_table(20, 180, w - 40, h - 240, order_.purchase);
    add_button->callback([](Fl_Widget*, void* w) { static_cast<Order_edit_window*>(w)->add_purchase(); }, this);

    resizable(purchase_table_);
    end();
}

void Order_edit_window::fill_order_info() {
    customer_name_input_->value(order_.customer_name.c_str());
    address_input_->value(order_.address.c_str());
    phone_number_input_->value(order_.phone_number.c_str());
    purchase_table_->update_content();
}

void Order_edit_window::add_purchase() {
    order_.purchase.emplace_back();
    purchase_table_->update_content();
}
