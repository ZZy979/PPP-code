#pragma once

#include "Graph.h"

// 第12章习题中的自定义形状类
namespace Graph_lib {

// 圆弧
struct Arc : public Circle {
    Arc(Point center, int radius, int a1, int a2) :Circle(center, radius), a1(a1), a2(a2) {}
    void draw_lines() const override;

private:
    int a1, a2;
};

// 正多边形
struct Regular_polygon : public Polygon {
    Regular_polygon(Point center, int radius, int n, int rotate = 0);
    Point center() const { return Point(point(0).x - r, point(0).y); }
    int radius() const { return r; }

private:
    int r;
};

// 超椭圆：|x/a|^n + |y/b|^n = 1
struct Super_ellipse : public Shape {
    Super_ellipse(Point center, int a, int b, double n, int count = 1000);
};

}
