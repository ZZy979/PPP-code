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
    return 0;
}
