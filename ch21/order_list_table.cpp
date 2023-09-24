#include "order_list_table.h"

#include <iomanip>
#include <sstream>

#include <FL/fl_draw.H>

const std::vector<std::string> Order_list_table::COLUMN_NAMES = {"Customer name", "Address", "Phone number", "Purchases", "Value"};
const std::vector<int> Order_list_table::COLUMN_WIDTH = {120, 150, 120, 250, 100};

Order_list_table::Order_list_table(int x, int y, int w, int h, std::vector<Order>& orders)
        :Fl_Table(x, y, w, h), orders_(orders) {
    update_content();
}

void Order_list_table::update_content() {
    cols(COLUMN_NAMES.size());
    col_header(1);
    col_resize(0);
    col_header_height(25);
    for (int c = 0; c < cols(); ++c)
        col_width(c, COLUMN_WIDTH[c]);

    rows(orders_.size());
    row_header(0);
    row_resize(0);
    row_height_all(25);

    redraw();
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
            fl_draw(get_column_text(orders_[R], C).c_str(), X + 3, Y + 3, W - 6, H - 6, FL_ALIGN_LEFT);
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
