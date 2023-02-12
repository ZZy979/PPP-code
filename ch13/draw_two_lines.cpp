#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw two lines
int main() {
    Simple_window win(Point(100, 100), 600, 400, "two lines");

    Line horizontal(Point(100, 100), Point(200, 100));  // make a horizontal line
    Line vertical(Point(150, 50), Point(150, 150));     // make a vertical line

    win.attach(horizontal);     // attach the lines to the window
    win.attach(vertical);
    win.wait_for_button();

    horizontal.set_color(Color::red);
    vertical.set_color(Color::green);
    win.set_label("two lines colored");
    win.wait_for_button();
    return 0;
}
