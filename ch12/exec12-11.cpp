#include "Graph.h"
#include "Simple_window.h"
#include "exec12_graph.h"

using namespace Graph_lib;

// Draw a series of regular polygons, one inside the other.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Regular polygons");

    Point center(300, 200);
    int radius = 100;
    Vector_ref<Regular_polygon*> v;
    for (int n = 3; n <= 6; ++n) {
        Regular_polygon* p = new Regular_polygon(center, radius, n);
        v.push_back(p);
        win.attach(*p);
    }
    win.wait_for_button();
    return 0;
}
