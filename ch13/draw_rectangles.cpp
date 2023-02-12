#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw rectangles
int main() {
    Simple_window win(Point(100, 100), 600, 400, "rectangles");

    Graph_lib::Rectangle rect00(Point(150, 100), 200, 100);
    Graph_lib::Rectangle rect11(Point(50, 50), Point(250, 150));
    Graph_lib::Rectangle rect12(Point(50, 150), Point(250, 250));   // just below rect11
    Graph_lib::Rectangle rect21(Point(250, 50), 200, 100);          // just to the right of rect11
    Graph_lib::Rectangle rect22(Point(250, 150), 200, 100);         // just below rect21

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);
    win.attach(rect22);
    win.wait_for_button();

    rect11.move(400, 0);    // to the right of rect21
    rect11.set_fill_color(Color::white);
    win.set_label("rectangles 2");
    win.wait_for_button();

    win.put_on_top(rect00);
    win.set_label("rectangles 3");
    win.wait_for_button();

    rect00.set_color(Color::invisible);
    rect11.set_color(Color::invisible);
    rect12.set_color(Color::invisible);
    rect21.set_color(Color::invisible);
    rect22.set_color(Color::invisible);
    win.set_label("rectangles 4");
    win.wait_for_button();
    return 0;
}
