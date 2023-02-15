#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw a closed polyline
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Closed polyline");

    Closed_polyline cpl = {{100, 100}, {150, 200}, {250, 250}, {300, 200}};
    win.attach(cpl);
    win.wait_for_button();

    cpl.add(Point(100, 250));
    win.set_label("Closed polyline 2");
    win.wait_for_button();

    Text t(Point(200, 200), "A closed polyline that isn't a polygon");
    t.set_color(Color::blue);
    win.attach(t);
    win.set_label("Closed polyline with text");
    win.wait_for_button();
    return 0;
}
