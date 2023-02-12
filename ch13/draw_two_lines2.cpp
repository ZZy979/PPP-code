#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw two lines (as a single graphical object)
int main() {
    Simple_window win(Point(100, 100), 600, 400, "lines: +");

    Lines x = {
        {{100, 100}, {200, 100}},   // first line: horizontal
        {{150, 50}, {150, 150}}     // second line: vertical
    };
    win.attach(x);
    win.wait_for_button();
    return 0;
}
