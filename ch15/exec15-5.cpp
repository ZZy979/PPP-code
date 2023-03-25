#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

double term(int n) {
    return (n % 2 == 1 ? 1.0 : -1.0) / (2 * n - 1);
}

int main() {
    Simple_window win(Point(100, 100), 600, 400, "Leibniz's series");

    const Point origin(50, 350);
    const int xlength = 500, ylength = 320;
    const int x_scale = 20, y_scale = 300;
    Axis x(Axis::x, origin, xlength, xlength / x_scale, "n");
    Axis y(Axis::y, origin, ylength, ylength / y_scale, "S(n)");
    win.attach(x);
    win.attach(y);

    Function pi_4([](double) { return atan(1); }, 0, 25, origin, 400, x_scale, y_scale);
    pi_4.set_color(Color::red);
    win.attach(pi_4);

    Vector_ref<Mark> marks;
    double sum = 0;
    for (int n = 1; n <= 25; ++n) {
        sum += term(n);
        Mark* mark = new Mark(Point(origin.x + n * x_scale, origin.y - sum * y_scale), 'x');
        marks.push_back(mark);
        win.attach(*mark);
        win.set_label("Leibniz's series: n = " + std::to_string(n));
        win.wait_for_button();
    }
    return 0;
}
