#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw a polygon
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Polygon");

    Graph_lib::Polygon poly = {{100, 100}, {150, 200}, {250, 250}, {300, 200}};
    win.attach(poly);
    win.wait_for_button();
    return 0;
}
