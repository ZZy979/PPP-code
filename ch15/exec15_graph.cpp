#include "exec15_graph.h"

#include <algorithm>
#include <sstream>

#include <FL/fl_draw.H>

namespace Graph_lib {

ResettableFunction::ResettableFunction(
        Fct f, double r1, double r2, Point origin, int n_points, double x_scale, double y_scale)
        :f_(f), r1_(r1), r2_(r2), origin_(origin), n_points_(n_points), x_scale_(x_scale), y_scale_(y_scale) {
    if (r1 >= r2)
        error("ResettableFunction: bad graphing range");
    if (n_points <= 0)
        error("ResettableFunction: non-positive graphing count");
    generate_points();
}

void ResettableFunction::set_range(double r1, double r2) {
    if (r1 >= r2)
        error("ResettableFunction: bad graphing range");
    r1_ = r1;
    r2_ = r2;
    generate_points();
}

void ResettableFunction::set_n_points(int n_points) {
    if (n_points <= 0)
        error("ResettableFunction: non-positive graphing count");
    n_points_ = n_points;
    generate_points();
}

void ResettableFunction::set_scale(double x_scale, double y_scale) {
    x_scale_ = x_scale;
    y_scale_ = y_scale;
    generate_points();
}

void ResettableFunction::draw_lines() const {
    if (color().visibility() && points_.size() > 1)
        for (int i = 1; i < points_.size(); ++i)
            fl_line(points_[i - 1].x, points_[i - 1].y, points_[i].x, points_[i].y);
}

void ResettableFunction::generate_points() {
    points_.clear();
    double d = (r2_ - r1_) / n_points_;
    for (double r = r1_; r < r2_; r += d)
        points_.emplace_back(origin_.x + int(r * x_scale_), origin_.y - int(f_(r) * y_scale_));
}

BarGraph::BarGraph(
        Point top_left, int width, int height, const vector<double>& data,
        const vector<string>& labels, const string& title,
        double d_min, double d_max, int bar_width, int font_size)
        :data_(data),
        border_(top_left, width, height),
        title_(Point(top_left.x + 50, top_left.y - 20), title) {
    if (data.empty())
        error("BarGraph: data is empty");
    if (data.size() != labels.size())
        error("BarGraph: data and labels have different sizes");
    if (bar_width <= 0 || width < bar_width * (data.size() + 1))
        error("BarGraph: invalid bar width");

    d_min_ = min(d_min, *min_element(data.begin(), data.end()));
    d_max_ = max(d_max, *max_element(data.begin(), data.end()));
    title_.set_font_size(font_size);

    int y_bottom = top_left.y + height;
    for (int i = 0; i < data.size(); ++i) {
        int x = top_left.x + (i + 1) * width / (data.size() + 1);
        int y = data_to_coordinate(data[i]);

        Rectangle* bar = new Rectangle(Point(x - bar_width / 2, y), Point(x + bar_width / 2, y_bottom));
        bar->set_color(Color::invisible);
        bar->set_fill_color(Color::black);
        bars_.push_back(bar);
        
        Text* bar_label = new Text(Point(x - bar_width / 2, y_bottom + 20), labels[i]);
        bar_label->set_font_size(font_size);
        bar_labels_.push_back(bar_label);

        std::ostringstream oss;
        oss << data[i];
        Text* data_label = new Text(Point(x - bar_width / 2, y - 20), oss.str());
        data_label->set_font_size(font_size);
        data_labels_.push_back(data_label);
    }
}

void BarGraph::set_fill_color(Color color) {
    for (int i = 0; i < bars_.size(); ++i)
        bars_[i].set_fill_color(color);
}

void BarGraph::move(int dx, int dy) {
    error("BarGraph is too heavy to move");
}

void BarGraph::draw_lines() const {
    for (int i = 0; i < bars_.size(); ++i) {
        bars_[i].draw();
        bar_labels_[i].draw();
        data_labels_[i].draw();
    }
    border_.draw();
    title_.draw();
}

int BarGraph::data_to_coordinate(double d) const {
    int y_bottom = border_.point(0).y + border_.height();
    // (d - d_min) / (d_max - d_min) = (y - y_bottom) / (y_top - y_bottom) = -(y - y_bottom) / height
    return y_bottom - max(1, int(border_.height() * (d - d_min_) / (d_max_ - d_min_)));
}

}
