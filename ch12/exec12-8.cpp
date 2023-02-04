#include "Graph.h"
#include "Simple_window.h"

namespace Graph_lib {
struct Arc : public Circle {
    Arc(Point center, int radius, int a1, int a2) :Circle(center, radius), a1(a1), a2(a2) {}

    void draw_lines() const override {
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

private:
    int a1, a2;
};
}

using namespace Graph_lib;

// Draw the Olympic five rings.
// https://www.olympic.sk/sites/default/files/field_media_file/2019-03/1.%20Olympism%20and%20the%20Olympic%20symbol%20-%20Principles%20and%20usage%20guidelines.pdf
int main() {
    const int scale = 10, r = 11 * scale, d = 2 * scale;
    const int width = 6 * r + 5 * d, height = 3 * r + d;
    const int x_margin = r, y_margin = r;
    const int win_width = width + 2 * x_margin, win_height = height + 2 * y_margin;

    Simple_window win(Point(100, 100), win_width, win_height, "Olympic rings");

    Graph_lib::Rectangle background(Point(0, 0), win_width, win_height);
    background.set_color(Color::invisible);
    background.set_fill_color(Color::white);
    win.attach(background);

    Line_style line_style = Line_style(Line_style::solid, d);
    Circle blue_ring(Point(x_margin + r + d / 2, y_margin + r + d / 2), r);
    blue_ring.set_color(0x0081C800);
    blue_ring.set_style(line_style);
    win.attach(blue_ring);

    Circle black_ring(Point(x_margin + 3 * r + 5 * d / 2, y_margin + r + d / 2), r);
    black_ring.set_color(0x00000000);
    black_ring.set_style(line_style);
    win.attach(black_ring);

    Circle red_ring(Point(x_margin + 5 * r + 9 * d / 2, y_margin + r + d / 2), r);
    red_ring.set_color(0xEE334E00);
    red_ring.set_style(line_style);
    win.attach(red_ring);

    Circle yellow_ring(Point(x_margin + 2 * r + 3 * d / 2, y_margin + 2 * r + d / 2), r);
    yellow_ring.set_color(0xFCB13100);
    yellow_ring.set_style(line_style);
    win.attach(yellow_ring);

    Circle green_ring(Point(x_margin + 4 * r + 7 * d / 2, y_margin + 2 * r + d / 2), r);
    green_ring.set_color(0x00A65100);
    green_ring.set_style(line_style);
    win.attach(green_ring);

    // redraw overlap
    Graph_lib::Arc blue_arc(blue_ring.center(), blue_ring.radius(), -30, 30);
    blue_arc.set_color(blue_ring.color());
    blue_arc.set_style(line_style);
    win.attach(blue_arc);

    Graph_lib::Arc black_arc1(black_ring.center(), black_ring.radius(), 210, 270);
    black_arc1.set_color(black_ring.color());
    black_arc1.set_style(line_style);
    win.attach(black_arc1);

    Graph_lib::Arc black_arc2(black_ring.center(), black_ring.radius(), -30, 30);
    black_arc2.set_color(black_ring.color());
    black_arc2.set_style(line_style);
    win.attach(black_arc2);

    Graph_lib::Arc red_arc(red_ring.center(), red_ring.radius(), 210, 270);
    red_arc.set_color(red_ring.color());
    red_arc.set_style(line_style);
    win.attach(red_arc);

    win.wait_for_button();
    return 0;
}
