#include <stdexcept>

#include "Graph.h"
#include "Simple_window.h"

namespace Graph_lib {
// |x/a|^n + |y/b|^n = 1
struct Superellipse : public Shape {
    Superellipse(Point center, int a, int b, double n, int count = 1000) {
        if (a <= 0 || b <= 0 || n <= 0 || count <= 0)
            error("invalid argument");

        // x = a(cos t)^(2/n), y = b(sin t)^(2/n)
        const double pi = 3.14159265358, delta = pi / (2 * count);
        double theta = 0;
        vector<Point> vp1, vp2, vp3, vp4;
        for (int i = 0; i < count; ++i, theta += delta) {
            double x = a * pow(cos(theta), 2.0 / n), y = b * pow(sin(theta), 2.0 / n);
            vp1.emplace_back(center.x + x, center.y + y);
            vp2.emplace_back(center.x - x, center.y + y);
            vp3.emplace_back(center.x - x, center.y - y);
            vp4.emplace_back(center.x + x, center.y - y);
        }

        for (const Point& p : vp1)
            add(p);
        for (auto it = vp2.rbegin(); it != vp2.rend(); ++it)
            add(*it);
        for (const Point& p : vp3)
            add(p);
        for (auto it = vp4.rbegin(); it != vp4.rend(); ++it)
            add(*it);
    }
};
}

using namespace Graph_lib;

// Draw "starlike" patterns by a superellipse.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Superellipse");

    Point center(300, 200);
    vector<double> vn{0.5, 1, 2, 4};
    Vector_ref<Superellipse*> v;
    for (double n : vn) {
        Superellipse* p = new Superellipse(center, 200, 100, n);
        v.push_back(p);
        win.attach(*p);
    }
    win.wait_for_button();
    return 0;
}
