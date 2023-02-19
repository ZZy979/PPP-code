#include "exec13_graph.h"

#include <cmath>

namespace Graph_lib {

void Elliptical_arc::draw_lines() const {
    if (fill_color().visibility()) {    // fill
        fl_color(fill_color().as_int());
        fl_pie(point(0).x, point(0).y, 2 * major() - 1, 2 * minor() - 1, a1, a2);
        fl_color(color().as_int());    // reset color
    }
    if (color().visibility()) {
        fl_color(color().as_int());
        fl_arc(point(0).x, point(0).y, 2 * major(), 2 * minor(), a1, a2);
    }
}

Rounded_rectangle::Rounded_rectangle(Point p, int w, int h, int r)
        :Rectangle(p, w, h),
        lines{
            {{p.x + r, p.y}, {p.x + w - r, p.y}},
            {{p.x + r, p.y + h}, {p.x + w - r, p.y + h}},
            {{p.x, p.y + r}, {p.x, p.y + h - r}},
            {{p.x + w, p.y + r}, {p.x + w, p.y + h - r}}
        },
        arc_top_right(Point(p.x + w - r, p.y + r), r, 0, 90),
        arc_top_left(Point(p.x + r, p.y + r), r, 90, 180),
        arc_bottom_left(Point(p.x + r, p.y + h - r), r, 180, 270),
        arc_bottom_right(Point(p.x + w - r, p.y + h - r), r, 270, 360),
        fill_rect1(Point(p.x, p.y + r), w, h - 2 * r),
        fill_rect2(Point(p.x + r, p.y), w - 2 * r, h) {
    if (r <= 0 || 2 * r > min(w, h))
        error("Bad rounded rectangle: invalid radius");
    fill_rect1.set_color(Color::invisible);
    fill_rect2.set_color(Color::invisible);
}

void Rounded_rectangle::set_color(Color color) {
    Shape::set_color(color);
    lines.set_color(color);
    arc_top_right.set_color(color);
    arc_top_left.set_color(color);
    arc_bottom_left.set_color(color);
    arc_bottom_right.set_color(color);
}

void Rounded_rectangle::set_style(Line_style style) {
    Shape::set_style(style);
    lines.set_style(style);
    arc_top_right.set_style(style);
    arc_top_left.set_style(style);
    arc_bottom_left.set_style(style);
    arc_bottom_right.set_style(style);
}

void Rounded_rectangle::set_fill_color(Color color) {
    Shape::set_fill_color(color);
    arc_top_right.set_fill_color(color);
    arc_top_left.set_fill_color(color);
    arc_bottom_left.set_fill_color(color);
    arc_bottom_right.set_fill_color(color);
    fill_rect1.set_fill_color(color);
    fill_rect2.set_fill_color(color);
}

void Rounded_rectangle::draw_lines() const {
    fill_rect1.draw_lines();
    fill_rect2.draw_lines();
    arc_top_right.draw_lines();
    arc_top_left.draw_lines();
    arc_bottom_left.draw_lines();
    arc_bottom_right.draw_lines();
    lines.draw_lines();
}

Arrow::Arrow(Point p1, Point p2) :Line(p1, p2) {
    if (p1 == p2)
        error("Bad arrow: two end points can't be the same");
    arrowhead.add(p2);

    const int w = 2, h = 5;     // 箭头小三角形底边的一半和高
    if (p1.x == p2.x) {
        int y = p2.y > p1.y ? p2.y - h : p2.y + h;
        arrowhead.add(Point(p1.x + w, y));
        arrowhead.add(Point(p1.x - w, y));
    }
    else {
        double k = double(p2.y - p1.y) / (p2.x - p1.x), d = sqrt(1 + k * k);
        double x0 = p2.x > p1.x ? p2.x - h / d : p2.x + h / d;  // 箭头小三角形底边中点坐标
        double y0 = p2.x > p1.x ? p2.y - h * k / d : p2.y + h * k / d;
        arrowhead.add(Point(x0 + w * k / d, y0 - w / d));   // 箭头小三角形底边端点坐标
        arrowhead.add(Point(x0 - w * k / d, y0 + w / d));
    }
    arrowhead.set_fill_color(color());
}

void Arrow::set_color(Color color) {
    Shape::set_color(color);
    arrowhead.set_color(color);
    arrowhead.set_fill_color(color);
}

void Arrow::draw_lines() const {
    Shape::draw_lines();
    arrowhead.draw_lines();
}

Point n(const Rectangle& r) {
    return Point(r.point(0).x + r.width() / 2, r.point(0).y);
}

Point s(const Rectangle& r) {
    return Point(r.point(0).x + r.width() / 2, r.point(0).y + r.height());
}

Point e(const Rectangle& r) {
    return Point(r.point(0).x + r.width(), r.point(0).y + r.height() / 2);
}

Point w(const Rectangle& r) {
    return Point(r.point(0).x, r.point(0).y + r.height() / 2);
}

Point center(const Rectangle& r) {
    return Point(r.point(0).x + r.width() / 2, r.point(0).y + r.height() / 2);
}

Point ne(const Rectangle& r) {
    return Point(r.point(0).x + r.width(), r.point(0).y);
}

Point se(const Rectangle& r) {
    return Point(r.point(0).x + r.width(), r.point(0).y + r.height());
}

Point sw(const Rectangle& r) {
    return Point(r.point(0).x, r.point(0).y + r.height());
}

Point nw(const Rectangle& r) {
    return r.point(0);
}

Point n(const Circle& c) {
    return Point(c.center().x, c.center().y - c.radius());
}

Point s(const Circle& c) {
    return Point(c.center().x, c.center().y + c.radius());
}

Point e(const Circle& c) {
    return Point(c.center().x + c.radius(), c.center().y);
}

Point w(const Circle& c) {
    return Point(c.center().x - c.radius(), c.center().y);
}

Point center(const Circle& c) {
    return c.center();
}

const double SQRT2 = sqrt(2);

Point ne(const Circle& c) {
    return Point(c.center().x + c.radius() / SQRT2, c.center().y - c.radius() / SQRT2);
}

Point se(const Circle& c) {
    return Point(c.center().x + c.radius() / SQRT2, c.center().y + c.radius() / SQRT2);
}

Point sw(const Circle& c) {
    return Point(c.center().x - c.radius() / SQRT2, c.center().y + c.radius() / SQRT2);
}

Point nw(const Circle& c) {
    return Point(c.center().x - c.radius() / SQRT2, c.center().y - c.radius() / SQRT2);
}

Point n(const Ellipse& e) {
    return Point(e.center().x, e.center().y - e.minor());
}

Point s(const Ellipse& e) {
    return Point(e.center().x, e.center().y + e.minor());
}

Point e(const Ellipse& e) {
    return Point(e.center().x + e.major(), e.center().y);
}

Point w(const Ellipse& e) {
    return Point(e.center().x - e.major(), e.center().y);
}

Point center(const Ellipse& e) {
    return e.center();
}

Point ne(const Ellipse& e) {
    return Point(e.center().x + e.major() / SQRT2, e.center().y - e.minor() / SQRT2);
}

Point se(const Ellipse& e) {
    return Point(e.center().x + e.major() / SQRT2, e.center().y + e.minor() / SQRT2);
}

Point sw(const Ellipse& e) {
    return Point(e.center().x - e.major() / SQRT2, e.center().y + e.minor() / SQRT2);
}

Point nw(const Ellipse& e) {
    return Point(e.center().x - e.major() / SQRT2, e.center().y - e.minor() / SQRT2);
}

void Box::draw_lines() const {
    Rectangle::draw_lines();
    label.draw_lines();
}

}
