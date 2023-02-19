#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// mark connection points on a circle and an ellipse
int main() {
    Simple_window win(Point(100, 100), 600, 400, "circle and ellipse connection points");

    Circle C(Point(150, 150), 100);
    Marks circle_marks("||--o/\\/\\", {n(C), s(C), e(C), w(C), center(C), ne(C), se(C), sw(C), nw(C)});
    win.attach(C);
    win.attach(circle_marks);

    Graph_lib::Ellipse E(Point(450, 150), 100, 50);
    Marks ellipse_marks("||--o/\\/\\", {n(E), s(E), e(E), w(E), center(E), ne(E), se(E), sw(E), nw(E)});
    win.attach(E);
    win.attach(ellipse_marks);
    win.wait_for_button();
    return 0;
}
