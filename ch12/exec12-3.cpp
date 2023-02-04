#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// Draw your initials 150 pixels high.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Name");

    Open_polyline first;
    first.add(Point(50, 50));
    first.add(Point(200, 50));
    first.add(Point(50, 200));
    first.add(Point(200, 200));
    first.set_color(Color::red);
    win.attach(first);

    Open_polyline second;
    second.add(Point(220, 50));
    second.add(Point(370, 50));
    second.add(Point(220, 200));
    second.add(Point(370, 200));
    second.set_color(Color::yellow);
    win.attach(second);

    Lines third;
    third.add(Point(390, 50), Point(465, 125));
    third.add(Point(540, 50), Point(465, 125));
    third.add(Point(465, 125), Point(465, 200));
    third.set_color(Color::green);
    win.attach(third);

    win.wait_for_button();
    return 0;
}
