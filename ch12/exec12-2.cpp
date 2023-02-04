#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// Draw a 100-by-30 Rectangle and place the text "Howdy!" inside it.
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Howdy");

    Graph_lib::Rectangle r(Point(100, 100), 100, 30);
    win.attach(r);

    Text t(Point(110, 120), "Howdy!");
    win.attach(t);

    win.wait_for_button();
    return 0;
}
