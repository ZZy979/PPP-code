#include <vector>
#include <string>

#include "Graph.h"
#include "Simple_window.h"
#include "exec13_graph.h"

using namespace Graph_lib;

// draw a class diagram
int main() {
    Simple_window win(Point(100, 100), 800, 400, "class diagram");

    const int width = 100, height = 30, margin = 10;
    Box shape(Point(340, 100), width, height, "Shape");
    win.attach(shape);

    vector<string> classes{"Line", "Lines", "Polygon", "Axis", "Rectangle", "Text", "Image"};
    Vector_ref<Box> subclasses;
    Vector_ref<Arrow> arrows;
    for (int i = 0; i < classes.size(); ++i) {
        Box* b = new Box(Point(margin + i * (width + margin), 200), width, height, classes[i]);
        subclasses.push_back(b);
        win.attach(*b);

        Arrow* a = new Arrow(n(*b), s(shape));
        arrows.push_back(a);
        win.attach(*a);
    }
    win.wait_for_button();
    return 0;
}
