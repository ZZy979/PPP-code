#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {
    Point tl(100, 100);     // top left corner of our window
    Simple_window win(tl, 600, 400, "Canvas");

    Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");    // make an Axis
    win.attach(xa);     // attach xa to the window, win
    Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
    ya.set_color(Color::cyan);              // choose a color
    ya.label.set_color(Color::dark_red);    // choose a color for the text
    win.attach(ya);

    Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);   // sine curve
    sine.set_color(Color::blue);
    win.attach(sine);

    Graph_lib::Polygon poly;
    poly.add(Point(300, 200));      // three points make a triangle
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));
    poly.set_color(Color::red);
    poly.set_style(Line_style(Line_style::dash, 4));
    win.attach(poly);

    Graph_lib::Rectangle r(Point(200, 200), 100, 50);   // top left corner, width, height
    r.set_fill_color(Color::yellow);    // color the inside of the rectangle
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point(100, 50));
    poly_rect.add(Point(200, 50));
    poly_rect.add(Point(200, 100));
    poly_rect.add(Point(100, 100));
    poly_rect.add(Point(50, 75));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.attach(poly_rect);

    Text t(Point(150, 150), "Hello, graphical world!");
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    // 必须在ch12目录下运行程序，否则会找不到文件
    Image ii(Point(100, 50), "img/image.jpg");  // 400*212-pixel jpg
    ii.move(100, 200);
    win.attach(ii);

    Circle c(Point(100, 200), 50);
    win.attach(c);

    Graph_lib::Ellipse e(Point(100, 200), 75, 25);
    e.set_color(Color::dark_red);
    win.attach(e);

    Mark m(Point(100, 200), 'x');
    win.attach(m);

    std::ostringstream oss;
    oss << "screen size: " << x_max() << '*' << y_max()
            << "; window size: " << win.x_max() << '*' << win.y_max();
    Text sizes(Point(100, 20), oss.str());
    win.attach(sizes);

    Image cal(Point(225, 225), "img/snow_cpp.gif");     // 320*240-pixel gif
    cal.set_mask(Point(40, 40), 200, 150);  // display center part of image
    win.attach(cal);

    win.set_label("Canvas #12");    // relabel the window
    win.wait_for_button();          // display!
    return 0;
}
