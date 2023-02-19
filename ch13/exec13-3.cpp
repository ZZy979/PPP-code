#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// draw lines with arrow
int main() {
    Simple_window win(Point(100, 100), 600, 400, "lines with arrow");

    Arrow a1(Point(50, 50), Point(100, 50));
    Arrow a2(Point(70, 70), Point(70, 100));
    Arrow a3(Point(200, 200), Point(300, 100));
    Arrow a4(Point(200, 200), Point(100, 100));
    Arrow a5(Point(200, 200), Point(100, 300));
    Arrow a6(Point(200, 200), Point(300, 300));

    a2.set_color(Color::cyan);
    a3.set_color(Color::red);
    a4.set_color(Color::yellow);
    a5.set_color(Color::green);
    a6.set_color(Color::blue);

    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
    win.attach(a4);
    win.attach(a5);
    win.attach(a6);
    win.wait_for_button();
    return 0;
}
