#pragma once

#include <string>
#include <utility>
#include <vector>

#include "Graph.h"

// 第15章习题中的自定义形状类
namespace Graph_lib {

// 提供“复位”操作的函数
class ResettableFunction : public Shape {
public:
    ResettableFunction(Fct f, double r1, double r2, Point origin, int n_points, double x_scale, double y_scale);

    Fct* function() const { return f_; }
    void set_function(Fct f) { f_ = f; }

    pair<double, double> range() const { return make_pair(r1_, r2_); }
    void set_range(double r1, double r2);

    const Point& origin() const { return origin_; }
    void set_origin(const Point& origin) { origin_ = origin; }

    int n_points() const { return n_points_; }
    void set_n_points(int n_points);

    pair<double, double> scale() const { return make_pair(x_scale_, y_scale_); }
    void set_scale(double x_scale, double y_scale);

protected:
    void draw_lines() const override;
    void generate_points();

private:
    Fct* f_;
    double r1_, r2_;
    Point origin_;
    int n_points_;
    double x_scale_, y_scale_;
    vector<Point> points_;     // Shape::points是private，且未提供clear_points()函数
};

// 柱状图
class BarGraph : public Shape {
public:
    BarGraph(
            Point top_left, int width, int height, const vector<double>& data,
            const vector<string>& labels, const string& title = "",
            double d_min = 0, double d_max = 0, int bar_width = 20, int font_size = 14);
    void set_fill_color(Color color);
    void move(int dx, int dy) override;

protected:
    void draw_lines() const override;

private:
    int data_to_coordinate(double d) const;

    vector<double> data_;
    double d_min_, d_max_;

    Rectangle border_;
    Vector_ref<Rectangle> bars_;
    Vector_ref<Text> bar_labels_;
    Vector_ref<Text> data_labels_;
    Text title_;
};

}
