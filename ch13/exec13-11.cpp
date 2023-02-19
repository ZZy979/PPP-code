#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw an ellipse and focal radius
int main() {
    Simple_window win(Point(100, 100), 600, 400, "ellipse and focal radius");

    Graph_lib::Ellipse e(Point(300, 200), 150, 100);
    Axis x_axis(Axis::x, Point(100, 200), 400, 40, "x");
    Axis y_axis(Axis::y, Point(300, 350), 300, 30, "y");
    Point p(350, 200 - 200 * sqrt(2) / 3);
    Mark a(p, 'o'), f1(e.focus1(), 'o'), f2(e.focus2(), 'o');
    Line line1(p, e.focus1()), line2(p, e.focus2());

    win.attach(e);
    win.attach(x_axis);
    win.attach(y_axis);
    win.attach(a);
    win.attach(f1);
    win.attach(f2);
    win.attach(line1);
    win.attach(line2);
    win.wait_for_button();
    return 0;
}
