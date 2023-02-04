#include <stdexcept>

#include "Graph.h"
#include "Simple_window.h"

namespace Graph_lib {
struct Regular_polygon : public Polygon {
    Regular_polygon(Point center, int radius, int n) {
        if (n < 3)
            error("less than 3 points in a Polygon");
        const double pi = 3.14159265358;
        for (int k = 0; k < n; ++k) {
            double theta = 2 * k * pi / n;
            Closed_polyline::add(Point(center.x + radius * cos(theta), center.y + radius * sin(theta)));
        }
    }
};
}

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
