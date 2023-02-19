#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// draw elliptical arcs
int main() {
    Simple_window win(Point(100, 100), 600, 400, "elliptical arcs");

    Elliptical_arc e1(Point(200, 200), 100, 150, 90, 360);
    Elliptical_arc e2(Point(200, 200), 100, 50, 0, 270);
    Elliptical_arc e3(Point(200, 200), 50, 50, -90, 180);
    e1.set_fill_color(Color::red);
    e2.set_fill_color(Color::yellow);
    e3.set_fill_color(Color::green);
    win.attach(e1);
    win.attach(e2);
    win.attach(e3);
    win.wait_for_button();
    return 0;
}
