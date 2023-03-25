#include <cmath>
#include <string>

#include "Graph.h"
#include "Simple_window.h"
#include "exec15_graph.h"

using namespace Graph_lib;

struct Setting {
    Fct* f;
    std::string label;
    Color color = Color::black;
    double r1 = -15;
    double r2 = 15;
};

int main() {
    const int xmax = 600, ymax = 400;
    Simple_window win(Point(100, 100), xmax, ymax, "Function graphing");

    const Point origin(xmax / 2, ymax / 2);
    const int scale = 20;
    Axis x(Axis::x, Point(0, origin.y), xmax, xmax / scale);
    Axis y(Axis::y, Point(origin.x, ymax), ymax, ymax / scale);
    win.attach(x);
    win.attach(y);

    ResettableFunction fct([](double x) { return x * x; }, -10, 11, origin, 400, scale, scale);
    win.attach(fct);

    Text label(Point(50, 50), "y = x^2");
    win.attach(label);
    win.wait_for_button();

    Setting settings[] = {
        {sqrt, "y = sqrt(x)", Color::red, 0, 15},
        {exp, "y = e^x", Color::dark_green},
        {log, "y = ln x", Color::blue, 0, 15},
        {sin, "y = sin x", Color::red},
        {cos, "y = cos x", Color::dark_green},
        {tan, "y = tan x", Color::blue},
        {[](double x) { return 1 / tan(x); }, "y = cot x", Color::red},
        {[](double x) { return 1 / cos(x); }, "y = sec x", Color::dark_green},
        {[](double x) { return 1 / sin(x); }, "y = csc x", Color::blue}
    };

    for (const Setting& s : settings) {
        fct.set_function(s.f);
        fct.set_color(s.color);
        fct.set_range(s.r1, s.r2);
        label.set_label(s.label);
        win.set_label(s.label);
        win.wait_for_button();
    }
    return 0;
}
