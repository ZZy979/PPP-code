#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// Draw a rectangle as a Rectangle and as a Polygon.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Rectangle");

    Graph_lib::Rectangle r(Point(100, 100), 100, 50);
    r.set_color(Color::blue);
    win.attach(r);

    Graph_lib::Polygon poly;
    poly.add(Point(300, 100));
    poly.add(Point(400, 100));
    poly.add(Point(400, 150));
    poly.add(Point(300, 150));
    poly.set_color(Color::red);
    win.attach(poly);

    win.wait_for_button();
    return 0;
}
