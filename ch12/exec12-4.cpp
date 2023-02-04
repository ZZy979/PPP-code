#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
int main() {
    Simple_window win(Point(100, 100), 300, 300, "Tic-Tac-Toe");

    Vector_ref<Graph_lib::Rectangle> v;
    const int side = 100;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            Graph_lib::Rectangle* r = new Graph_lib::Rectangle(Point(i * side, j * side), side, side);
            r->set_color(Color::invisible);
            r->set_fill_color((i + j) % 2 == 0 ? Color::white : Color::red);
            win.attach(*r);
            v.push_back(r);
        }

    win.wait_for_button();
    return 0;
}
