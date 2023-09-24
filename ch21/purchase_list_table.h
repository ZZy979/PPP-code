#pragma once

#include <string>
#include <vector>

#include <FL/Fl_Table.H>

#include "order.h"

// A table of purchases;
class Purchase_list_table : public Fl_Table {
public:
    Purchase_list_table(int x, int y, int w, int h, std::vector<Purchase>& purchases);

    void update_content();

protected:
    void draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H) override;

private:
    static const std::vector<std::string> COLUMN_NAMES;
    static const std::vector<int> COLUMN_WIDTH;

    std::vector<Purchase>& purchases_;
};
