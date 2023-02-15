#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw circles
int main() {
    Simple_window win(Point(100, 100), 600, 400, "circles");

    Circle c1(Point(100, 200), 50);
    Circle c2(Point(150, 200), 100);
    Circle c3(Point(200, 200), 150);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.wait_for_button();

    c1.set_color(Color::blue);
    c2.set_color(Color::red);
    c3.set_color(Color::green);
    Mark m1(Point(100, 200), 'x');
    Mark m2(Point(150, 200), 'y');
    Mark m3(Point(200, 200), 'z');
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);
    win.set_label("circles with centers marked");
    win.wait_for_button();
    return 0;
}
