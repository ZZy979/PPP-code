#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// Draw a two-dimensional house seen from the front.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "House");

    Graph_lib::Rectangle house(Point(200, 200), 200, 200);
    house.set_color(Color::invisible);
    house.set_fill_color(Color::yellow);
    win.attach(house);

    Graph_lib::Rectangle door(Point(275, 300), 50, 100);
    door.set_color(Color::invisible);
    door.set_fill_color(Color::dark_yellow);
    win.attach(door);

    Graph_lib::Rectangle left_window(Point(225, 225), 50, 50);
    left_window.set_color(Color::invisible);
    left_window.set_fill_color(Color::cyan);
    win.attach(left_window);

    Graph_lib::Rectangle right_window(Point(325, 225), 50, 50);
    right_window.set_color(Color::invisible);
    right_window.set_fill_color(Color::cyan);
    win.attach(right_window);

    Graph_lib::Rectangle chimney(Point(375, 75), 25, 125);
    chimney.set_color(Color::invisible);
    chimney.set_fill_color(Color::dark_red);
    win.attach(chimney);

    Graph_lib::Polygon roof;
    roof.add(Point(150, 200));
    roof.add(Point(300, 50));
    roof.add(Point(450, 200));
    roof.set_color(Color::invisible);
    roof.set_fill_color(Color::red);
    win.attach(roof);

    Graph_lib::Ellipse smoke1(Point(400, 50), 20, 10);
    smoke1.set_fill_color(Color::white);
    win.attach(smoke1);

    Graph_lib::Ellipse smoke2(Point(450, 30), 20, 10);
    smoke2.set_fill_color(Color::white);
    win.attach(smoke2);

    Graph_lib::Ellipse smoke3(Point(500, 10), 20, 10);
    smoke3.set_fill_color(Color::white);
    win.attach(smoke3);

    win.wait_for_button();
    return 0;
}
