#include "lines_window.h"

#include <sstream>

namespace Graph_lib {

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
        :Window(xy, w, h, title),
        next_button(Point(x_max() - 150, 0), 70, 20, "Next point",
                [](Address, Address pw) { reference_to<Lines_window>(pw).next(); }),
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit",
                [](Address, Address pw) { reference_to<Lines_window>(pw).quit(); }),
        next_x(Point(x_max() - 310, 0), 50, 20, "next x:"),
        next_y(Point(x_max() - 210, 0), 50, 20, "next y:"),
        xy_out(Point(100, 0), 100, 20, "current (x,y):") {
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
}

void Lines_window::next() {
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point(x, y));

    // update current position readout:
    std::ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::quit() {
    hide();     // curious FLTK idiom to delete window
}

}
