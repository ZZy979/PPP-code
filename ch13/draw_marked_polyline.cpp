#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw a marked polyline
int main() {
    Simple_window win(Point(100, 100), 600, 400, "marked polyline");

    Marked_polyline mpl{"1234", {{100, 100}, {150, 200}, {250, 250}, {300, 200}}};
    win.attach(mpl);
    win.wait_for_button();
    return 0;
}
