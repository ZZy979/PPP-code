#include <cmath>
#include <sstream>

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

double fac(int n);
double term(double x, int n);
double expe(double x, int n);

int expN_number_of_terms = 10;

double expN(double x);

// exponential function approximation
int main() {
    const int xmax = 600;           // window size
    const int ymax = 400;

    const int x_orig = xmax / 2;    // position of (0,0) is center of window
    const int y_orig = ymax / 2;
    const Point orig(x_orig, y_orig);

    const int r_min = -10;          // range [-10,11)
    const int r_max = 11;

    const int n_points = 200;       // number of points used in range

    const int x_scale = 30;         // scaling factors
    const int y_scale = 30;

    const int xlength = xmax - 40;  // make the axis a bit smaller than the window
    const int ylength = ymax - 40;

    Simple_window win(Point(100, 100), xmax, ymax, "exp approximation");

    Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale);
    Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale);
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

    Function real_exp(exp, r_min, r_max, orig, n_points, x_scale, y_scale);
    real_exp.set_color(Color::blue);
    win.attach(real_exp);

    for (int n = 0; n < 20; ++n) {
        std::ostringstream ss;
        ss << "exp approximation; n==" << n;
        win.set_label(ss.str());
        // get next approximation:
        expN_number_of_terms = n;
        Function e(expN, r_min, r_max, orig, n_points, x_scale, y_scale);
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }
    return 0;
}

// factorial(n); n!
double fac(int n) {
    double r = 1;
    while (n > 1)
        r *= n--;
    return r;
}

// nth term of series
double term(double x, int n) {
    return pow(x, n) / fac(n);
}

// sum of n terms for x
double expe(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

double expN(double x) {
    return expe(x, expN_number_of_terms);
}
