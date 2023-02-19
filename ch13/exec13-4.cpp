#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// mark connection points on a rectangle
int main() {
    Simple_window win(Point(100, 100), 600, 400, "rectangle connection points");

    Graph_lib::Rectangle r(Point(100, 100), Point(300, 200));
    Marks marks("||--o/\\/\\", {n(r), s(r), e(r), w(r), center(r), ne(r), se(r), sw(r), nw(r)});
	win.attach(r);
    win.attach(marks);
    win.wait_for_button();
    return 0;
}
