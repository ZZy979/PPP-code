#include "exec12_graph.h"

namespace Graph_lib {

void Arc::draw_lines() const {
    if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
        fl_pie(point(0).x, point(0).y, 2 * radius() - 1, 2 * radius() - 1, a1, a2);
        fl_color(color().as_int());    // reset color
    }
    if (color().visibility()) {
        fl_color(color().as_int());
        fl_arc(point(0).x, point(0).y, 2 * radius(), 2 * radius(), a1, a2);
    }
}

Regular_polygon::Regular_polygon(Point center, int radius, int n) :r(radius) {
    if (n < 3)
        error("Bad regular polygon: less than 3 points in a Polygon");
    if (radius <= 0)
        error("Bad regular polygon: non-positive radius");

    const double pi = 3.14159265358;
    for (int k = 0; k < n; ++k) {
        double theta = 2 * k * pi / n;
        Closed_polyline::add(Point(center.x + radius * cos(theta), center.y + radius * sin(theta)));
    }
}

Super_ellipse::Super_ellipse(Point center, int a, int b, double n, int count) {
    if (a <= 0 || b <= 0 || n <= 0 || count <= 0)
        error("Bad super ellipse: invalid argument");

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

}
