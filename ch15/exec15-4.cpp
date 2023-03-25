#include <cmath>

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {
    const int xmax = 600, ymax = 400;
    Simple_window win(Point(100, 100), xmax, ymax, "Function graphing");

    const Point origin(xmax / 2, ymax / 2);
    const int scale = 40;
    Axis x(Axis::x, Point(0, origin.y), xmax, xmax / scale);
    Axis y(Axis::y, Point(origin.x, ymax), ymax, ymax / scale);
    win.attach(x);
    win.attach(y);

    const int r_min = -10, r_max = 10, n_points = 400;
    Function f1(sin, r_min, r_max, origin, n_points, scale, scale);
    Function f2(cos, r_min, r_max, origin, n_points, scale, scale);
    Function f3([](double x) { return sin(x) + cos(x); }, r_min, r_max, origin, n_points, scale, scale);
    Function f4(
            [](double x) { return sin(x) * sin(x) + cos(x) * cos(x); },
            r_min, r_max, origin, n_points, scale, scale);
    f1.set_color(Color::red);
    f2.set_color(Color::dark_yellow);
    f3.set_color(Color::dark_green);
    f4.set_color(Color::blue);

    Text t1(Point(50, 50), "y = sin x");
    Text t2(Point(50, 70), "y = cos x");
    Text t3(Point(50, 90), "y = sin x + cos x");
    Text t4(Point(50, 110), "y = (sin x)^2 + (cos x)^2");
    t1.set_color(Color::red);
    t2.set_color(Color::dark_yellow);
    t3.set_color(Color::dark_green);
    t4.set_color(Color::blue);

    win.attach(x);
    win.attach(y);
    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.attach(t1);
    win.attach(t2);
    win.attach(t3);
    win.attach(t4);
    win.wait_for_button();
    return 0;
}
