#include "order_list_table.h"

#include <iomanip>
#include <sstream>

#include <FL/fl_draw.H>

#include "order_list_window.h"

const std::vector<std::string> Order_list_table::COLUMN_NAMES = {"Customer name", "Address", "Phone number", "Purchases", "Value"};
const std::vector<int> Order_list_table::COLUMN_WIDTH = {120, 150, 120, 250, 100};

Order_list_table::Order_list_table(int x, int y, int w, int h) :Fl_Table(x, y, w, h) {
    end();

    // create sub-window after end()
    edit_window_ = std::make_unique<Order_edit_window>(600, 600, "Edit order");
    edit_window_->ok_callback([](Fl_Widget*, void* w) { static_cast<Order_list_table*>(w)->update_order(); }, this);
    edit_window_->set_modal();

    set_table_size();
}

void Order_list_table::add_order() {
    edit_window_->set_order(Order());
    edit_window_->set_index(-1);
    edit_window_->show();
}

void Order_list_table::edit_order() {
    edit_window_->set_order(filtered_orders_[callback_row()]);
    edit_window_->set_index(callback_row());
    edit_window_->show();
}

void Order_list_table::filter_by_customer_name(const std::string& name) {
    if (name.empty())
        filter_ = nullptr;
    else
        filter_ = [&name](const Order& o) { return o.customer_name.find(name) != std::string::npos; };
    update_content();
}

// callback for Order_edit_window
void Order_list_table::update_order() {
    edit_window_->hide();
    if (edit_window_->index() == -1)  // add
        orders_.push_back(edit_window_->order());
    else  // edit
        orders_[edit_window_->index()] = edit_window_->order();
    update_content();
}

void Order_list_table::update_content() {
    filtered_orders_.clear();
    for (Order& o : orders_)
        if (!filter_ || filter_(o))
            filtered_orders_.push_back(std::ref(o));

    set_table_size();
    redraw();
    dynamic_cast<Order_list_window*>(parent())->update_total_value();
}

void Order_list_table::set_table_size() {
    cols(COLUMN_NAMES.size());
    col_header(1);
    col_resize(0);
    col_header_height(25);
    for (int c = 0; c < cols(); ++c)
        col_width(c, COLUMN_WIDTH[c]);

    rows(filtered_orders_.size());
    row_header(0);
    row_resize(0);
    row_height_all(25);
}

void Order_list_table::draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H) {
    switch (context) {
        case CONTEXT_STARTPAGE:
            fl_font(FL_HELVETICA, 12);
            break;
        case CONTEXT_COL_HEADER:
            fl_push_clip(X, Y, W, H);
            fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
            fl_color(FL_BLACK);
            fl_draw(COLUMN_NAMES[C].c_str(), X, Y, W, H, FL_ALIGN_CENTER);
            fl_pop_clip();
            break;
        case CONTEXT_CELL: {
            fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, FL_WHITE);
            fl_push_clip(X + 3, Y + 3, W - 6, H - 6);
            fl_color(FL_BLACK);
            fl_draw(get_column_text(filtered_orders_[R], C).c_str(), X + 3, Y + 3, W - 6, H - 6, FL_ALIGN_LEFT);
            fl_pop_clip();
            break;
        }
        default:
            break;
    }
}

// return the text to display at column c for order o
std::string get_column_text(const Order& o, int c) {
    switch (c) {
        case 0:
            return o.customer_name;
        case 1:
            return o.address;
        case 2:
            return o.phone_number;
        case 3: {
            std::ostringstream oss;
            for (const Purchase& p : o.purchase)
                oss << p.product_name << '*' << p.count << ' ';
            return oss.str();
        }
        case 4: {
            std::stringstream oss;
            oss << std::fixed << std::setprecision(2) << get_order_value(o);
            return oss.str();
        }
        default:
            return "";
    }
}
