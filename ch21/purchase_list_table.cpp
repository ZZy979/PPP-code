#include "purchase_list_table.h"

#include <iomanip>
#include <sstream>

#include <FL/fl_draw.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>

const std::vector<std::string> Purchase_list_table::COLUMN_NAMES = {"Product name", "Unit price", "Count"};
const std::vector<int> Purchase_list_table::COLUMN_WIDTH = {200, 150, 150};

Purchase_list_table::Purchase_list_table(int x, int y, int w, int h, std::vector<Purchase>& purchases)
        :Fl_Table(x, y, w, h), purchases_(purchases) {
    update_content();
}

void Purchase_list_table::update_content() {
    clear();

    cols(COLUMN_NAMES.size());
    col_header(1);
    col_resize(0);
    col_header_height(25);
    for (int c = 0; c < cols(); ++c)
        col_width(c, COLUMN_WIDTH[c]);

    rows(purchases_.size());
    row_header(0);
    row_resize(0);
    row_height_all(25);

    begin();
    for (int r = 0; r < rows(); ++r) {
        Purchase& p = purchases_[r];
        for (int c = 0; c < cols(); ++c) {
            int x, y, w, h;
            find_cell(CONTEXT_TABLE, r, c, x, y, w, h);
            switch (c) {
                case 0: {  // product name
                    Fl_Input* input = new Fl_Input(x, y, w, h);
                    input->value(p.product_name.c_str());
                    input->callback([](Fl_Widget* w, void* p) {
                        static_cast<Purchase*>(p)->product_name = dynamic_cast<Fl_Input*>(w)->value();
                    }, &p);
                    break;
                }
                case 1: {  // unit price
                    Fl_Float_Input* input = new Fl_Float_Input(x, y, w, h);
                    std::ostringstream oss;
                    oss << std::fixed << std::setprecision(2) << p.unit_price;
                    input->value(oss.str().c_str());
                    input->callback([](Fl_Widget* w, void* p) {
                        static_cast<Purchase*>(p)->unit_price = std::stod(dynamic_cast<Fl_Float_Input*>(w)->value());
                    }, &p);
                    break;
                }
                case 2: {  // count
                    Fl_Int_Input* input = new Fl_Int_Input(x, y, w, h);
                    input->value(std::to_string(p.count).c_str());
                    input->callback([](Fl_Widget* w, void* p) {
                        static_cast<Purchase*>(p)->count = std::stoi(dynamic_cast<Fl_Int_Input*>(w)->value());
                    }, &p);
                    break;
                }
                default:
                    break;
            }
        }
    }
    end();
    redraw();
}

void Purchase_list_table::draw_cell(Fl_Table::TableContext context, int R, int C, int X, int Y, int W, int H) {
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
        case CONTEXT_RC_RESIZE: {
            int x, y, w, h, index = 0;
            for (int r = 0; r < rows(); ++r) {
                for (int c = 0; c < cols(); ++c) {
                    if (index > children()) break;
                    find_cell(CONTEXT_TABLE, r, c, x, y, w, h);
                    child(index++)->resize(x, y, w, h);
                }
            }
            init_sizes();
            break;
        }
        default:
            break;
    }
}
