#include <sstream>

#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// Move a mark around a circle
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Move a mark around a circle");

    Circle c(Point(300, 200), 100);
    Regular_polygon r(c.center(), c.radius(), 10);
    Mark m(r.point(0), 'o');
    win.attach(c);
    win.attach(m);

    for (int i = 0; i < r.number_of_points(); ++i) {
        m.move(r.point(i).x - m.point(0).x, r.point(i).y - m.point(0).y);
        ostringstream oss;
        oss << "Move a mark around a circle (" << i + 1 << '/' << r.number_of_points() << ')';
        win.set_label(oss.str());
        win.wait_for_button();
    }
    return 0;
}
