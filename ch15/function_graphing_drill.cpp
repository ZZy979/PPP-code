#include <cmath>

#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;

int main() {
    Graph_lib::Window win(Point(100, 100), 600, 600, "Function graphs");

    const int xlength = 400, ylength = 400, scale = 20;
    const int font_size = 14;

    Axis x(Axis::x, Point(100, 300), xlength, xlength / scale, "1 == 20 pixels");
    Axis y(Axis::y, Point(300, 500), ylength, ylength / scale, "1 == 20 pixels");
    x.set_color(Color::red);
    x.label.set_font_size(font_size);
    y.set_color(Color::red);
    y.label.set_font_size(font_size);
    win.attach(x);
    win.attach(y);

    const Point orig(300, 300);
    const int r_min = -10, r_max = 11, n_points = 400;

    Function one([](double x) { return 1.0; }, r_min, r_max, orig, n_points, scale, scale);
    Function slope([](double x) { return x / 2; }, r_min, r_max, orig, n_points, scale, scale);
    Function square([](double x) { return x * x; }, r_min, r_max, orig, n_points, scale, scale);
    Function cosine(cos, r_min, r_max, orig, n_points, scale, scale);
    cosine.set_color(Color::blue);
    Function sloping_cos([](double x) { return cos(x) + x / 2; }, r_min, r_max, orig, n_points, scale, scale);
    win.attach(one);
    win.attach(slope);
    win.attach(square);
    win.attach(cosine);
    win.attach(sloping_cos);

    Text slope_label(Point(100, 390), "x/2");
    slope_label.set_font_size(font_size);
    win.attach(slope_label);

    gui_main();
    return 0;
}
