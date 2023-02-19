#include <vector>

#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// regular hexagons tile
int main() {
    Simple_window win(Point(100, 100), 600, 400, "regular hexagons tile");

    const int radius = 50;
    Regular_polygon r(Point(300, 200), 50 * sqrt(3), 12);
    vector<Point> centers;
    for (int i = 1; i < r.number_of_points(); i += 2)
        centers.push_back(r.point(i));
    centers.push_back(r.center());

    Vector_ref<Regular_hexagon> hexagons;
    for (const Point& c : centers) {
        Regular_hexagon* h = new Regular_hexagon(c, radius);
        h->set_style(Line_style(Line_style::solid, 5));
        h->set_color(Color::dark_yellow);
        h->set_fill_color(Color::yellow);
        hexagons.push_back(h);
        win.attach(*h);
    }
    win.wait_for_button();
    return 0;
}
