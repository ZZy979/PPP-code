#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw a grid
int main() {
    Simple_window win(Point(100, 100), 600, 400, "grid");

    int x_size = win.x_max();   // get the size of our window
    int y_size = win.y_max();
    int x_grid = 80, y_grid = 40;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point(x, 0), Point(x, y_size));    // vertical line
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point(0, y), Point(x_size, y));    // horizontal line
    win.attach(grid);
    win.wait_for_button();

    grid.set_color(Color::red);
    win.set_label("red grid");
    win.wait_for_button();

    grid.set_style(Line_style::dot);
    win.set_label("red dotted grid");
    win.wait_for_button();

    grid.set_style(Line_style(Line_style::dash, 2));
    win.set_label("fat dashed red grid");
    win.wait_for_button();
    return 0;
}
