#include "order_list_window.h"

#include <fstream>
#include <iomanip>
#include <iterator>
#include <sstream>

#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>

static Fl_Menu_Item MENU_ITEMS[] = {
    {"&File", 0, 0, 0, FL_SUBMENU},
    {"&Open File...", FL_COMMAND + 'o', [](Fl_Widget*, void* w) { static_cast<Order_list_window*>(w)->load_file(); }},
    {"&Save File...", FL_COMMAND + 's', [](Fl_Widget*, void* w) { static_cast<Order_list_window*>(w)->save_file(); }},
    {"E&xit", FL_COMMAND + 'q', [](Fl_Widget*, void*) { exit(0); }},
    {0},

    {0}
};

Order_list_window::Order_list_window(int w, int h, const char* title) :Fl_Window(w, h, title) {
    Fl_Menu_Bar* menu_bar = new Fl_Menu_Bar(0, 0, w, 30);
    menu_bar->box(FL_THIN_UP_BOX);
    menu_bar->copy(MENU_ITEMS, this);

    Fl_Box* header = new Fl_Box(0, 30, w, 40, "Order Management");
    header->labelsize(20);

    Fl_Button* add_button = new Fl_Button(w - 120, 70, 100, 25, "Add");

    total_value_ = new Fl_Box(20, h - 50, w - 40, 30, "Total value: 0.00");
    total_value_->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

    // initialize table at last to avoid changing Fl_Group::current()
    order_table_ = new Order_list_table(20, 100, w - 40, h - 150, orders_);
    order_table_->callback([](Fl_Widget* t, void* w) {
        Order_list_table* table = dynamic_cast<Order_list_table*>(t);
        if (table->callback_context() == Fl_Table::CONTEXT_CELL)
            static_cast<Order_list_window*>(w)->edit_order(table->callback_row());
    }, this);
    add_button->callback([](Fl_Widget*, void* w) { static_cast<Order_list_window*>(w)->add_order(); }, this);

    resizable(order_table_);
    end();

    // create sub-window after end()
    edit_window_ = new Order_edit_window(600, 600, "Edit order");
    edit_window_->ok_callback([](Fl_Widget*, void* w) { static_cast<Order_list_window*>(w)->update_order(); }, this);
    edit_window_->set_modal();
}

Order_list_window::~Order_list_window() {
    delete edit_window_;
}

void Order_list_window::load_file() {
    if (const char* filename = fl_file_chooser("Choose order data file", "Text Files (*.txt)", "")) {
        try {
            std::ifstream ifs(filename);
            std::istream_iterator<Order> iit(ifs), eos;
            orders_.assign(iit, eos);
            order_table_->update_content();

            std::ostringstream oss;
            oss << "Total value: " << std::fixed << std::setprecision(2)
                    << get_total_value(orders_.begin(), orders_.end());
            total_value_->copy_label(oss.str().c_str());
        }
        catch (std::runtime_error& e) {
            fl_alert("Format error");
        }
    }
}

void Order_list_window::add_order() {
    orders_.emplace_back();
    edit_order(orders_.size() - 1);
}

void Order_list_window::edit_order(int i) {
    edit_window_->set_order(orders_[i]);
    edit_window_->set_index(i);
    edit_window_->show();
}

void Order_list_window::update_order() {
    edit_window_->hide();
    orders_[edit_window_->index()] = edit_window_->get_order();
    order_table_->update_content();
}

void Order_list_window::save_file() {
    if (const char* filename = fl_file_chooser("Choose file to save", "Text Files (*.txt)", "")) {
        std::ofstream ofs(filename);
        std::ostream_iterator<Order> oit(ofs, "\n");
        std::copy(orders_.begin(), orders_.end(), oit);
    }
}
