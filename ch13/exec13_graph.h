#pragma once

#include "Graph.h"
#include "ch12/exec12_graph.h"

// 第13章习题中的自定义形状类

namespace Graph_lib {

// 椭圆弧
struct Elliptical_arc : Ellipse {
    Elliptical_arc(Point center, int major, int minor, int a1, int a2)
            :Ellipse(center, major, minor), a1(a1), a2(a2) {}
    void draw_lines() const override;

private:
    int a1, a2;
};

// 圆角矩形
struct Rounded_rectangle : Rectangle {
    Rounded_rectangle(Point p, int w, int h, int r);
    Rounded_rectangle(Point p, int w, int h) :Rounded_rectangle(p, w, h, min(w, h) / 5.0) {}

    // 由于set_color()被Marks的构造函数调用了，因此不能将其声明为虚函数，只能使用隐藏
    void set_color(Color color);
    void set_style(Line_style style);
    void set_fill_color(Color color);
    void draw_lines() const override;

    int radius() const { return r; }

private:
    Lines lines;
    Arc arc_top_right, arc_top_left, arc_bottom_left, arc_bottom_right;
    Rectangle fill_rect1, fill_rect2;
    int r;
};

// 带箭头的线
struct Arrow : Line {
    Arrow(Point p1, Point p2);
    void set_color(Color color);
    void draw_lines() const override;

private:
    Polygon arrowhead;
};

// 矩形上的连接点
Point n(const Rectangle& r);
Point s(const Rectangle& r);
Point e(const Rectangle& r);
Point w(const Rectangle& r);
Point center(const Rectangle& r);
Point ne(const Rectangle& r);
Point se(const Rectangle& r);
Point sw(const Rectangle& r);
Point nw(const Rectangle& r);

// 圆上的连接点
Point n(const Circle& c);
Point s(const Circle& c);
Point e(const Circle& c);
Point w(const Circle& c);
Point center(const Circle& c);
Point ne(const Circle& c);
Point se(const Circle& c);
Point sw(const Circle& c);
Point nw(const Circle& c);

// 椭圆上的连接点
Point n(const Ellipse& e);
Point s(const Ellipse& e);
Point e(const Ellipse& e);
Point w(const Ellipse& e);
Point center(const Ellipse& e);
Point ne(const Ellipse& e);
Point se(const Ellipse& e);
Point sw(const Ellipse& e);
Point nw(const Ellipse& e);

// 带有文本标签的矩形
struct Box : Rectangle {
    Box(Point p, int w, int h, const string& text)
            :Rectangle(p, w, h), label(Point(p.x + 5, p.y + 20), text) {}
    void draw_lines() const override;

private:
    Text label;
};

// 正六边形
struct Regular_hexagon : Regular_polygon {
    Regular_hexagon(Point center, int radius) :Regular_polygon(center, radius, 6) {}
};

}
