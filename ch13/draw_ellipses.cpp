#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw ellipses
int main() {
    Simple_window win(Point(100, 100), 600, 400, "ellipses");

    Graph_lib::Ellipse e1(Point(200, 200), 50, 50);
    Graph_lib::Ellipse e2(Point(200, 200), 100, 50);
    Graph_lib::Ellipse e3(Point(200, 200), 100, 150);
    win.attach(e1);
    win.attach(e2);
    win.attach(e3);
    win.wait_for_button();
    return 0;
}
