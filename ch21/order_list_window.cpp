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

#include "order.h"

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

    customer_name_input_ = new Fl_Input(120, 70, w - 360, 25, "Customer name:");

    Fl_Button* query_button = new Fl_Button(w - 230, 70, 100, 25, "Query");
    query_button->callback(
            [](Fl_Widget*, void* w) { static_cast<Order_list_window*>(w)->query_by_customer_name(); }, this);

    Fl_Button* add_button = new Fl_Button(w - 120, 70, 100, 25, "Add");

    total_value_ = new Fl_Box(20, h - 50, w - 40, 30, "Total value: 0.00");
    total_value_->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);

    // initialize table at last to avoid changing Fl_Group::current()
    order_table_ = new Order_list_table(20, 105, w - 40, h - 155);
    order_table_->callback([](Fl_Widget* t, void*) {
        Order_list_table* table = dynamic_cast<Order_list_table*>(t);
        if (table->callback_context() == Fl_Table::CONTEXT_CELL)
            table->edit_order();
    });
    add_button->callback([](Fl_Widget*, void* t) { static_cast<Order_list_table*>(t)->add_order(); }, order_table_);

    resizable(order_table_);
    end();
}

void Order_list_window::load_file() const {
    if (const char* filename = fl_file_chooser("Choose order data file", "Text Files (*.txt)", "")) {
        try {
            std::ifstream ifs(filename);
            std::istream_iterator<Order> iit(ifs), eos;
            order_table_->orders().assign(iit, eos);
            order_table_->update_content();
        }
        catch (std::runtime_error& e) {
            fl_alert("Format error");
        }
    }
}

void Order_list_window::save_file() const {
    if (const char* filename = fl_file_chooser("Choose file to save", "Text Files (*.txt)", "")) {
        std::ofstream ofs(filename);
        std::ostream_iterator<Order> oit(ofs, "\n");
        auto orders = order_table_->orders();
        std::copy(orders.begin(), orders.end(), oit);
    }
}

void Order_list_window::query_by_customer_name() const {
    order_table_->filter_by_customer_name(customer_name_input_->value());
}

// automatically called by Order_list_table::update_content()
void Order_list_window::update_total_value() const {
    std::ostringstream oss;
    auto orders = order_table_->filtered_orders();
    oss << "Total value: " << std::fixed << std::setprecision(2)
            << get_total_value(orders.begin(), orders.end());
    total_value_->copy_label(oss.str().c_str());
}
