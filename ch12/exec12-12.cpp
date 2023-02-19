#include "Graph.h"
#include "Simple_window.h"
#include "exec12_graph.h"

using namespace Graph_lib;

// Draw "starlike" patterns by a superellipse.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Superellipse");

    Point center(300, 200);
    vector<double> vn{0.5, 1, 2, 4};
    Vector_ref<Super_ellipse> v;
    for (double n : vn) {
        Super_ellipse* p = new Super_ellipse(center, 200, 100, n);
        v.push_back(p);
        win.attach(*p);
    }
    win.wait_for_button();
    return 0;
}
