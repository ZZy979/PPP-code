#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw 16*16 color matrix
int main() {
    Simple_window win(Point(100, 100), 600, 400, "16*16 color matrix");
    Vector_ref<Graph_lib::Rectangle> vr;

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j) {
            vr.push_back(new Graph_lib::Rectangle(Point(i * 20, j * 20), 20, 20));
            vr[vr.size() - 1].set_fill_color(i * 16 + j);
            win.attach(vr[vr.size() - 1]);
        }
    win.wait_for_button();
    return 0;
}
