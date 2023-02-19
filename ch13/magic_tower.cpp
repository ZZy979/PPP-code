#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {
    Simple_window win(Point(100, 100), 1000, 800, "Magic Tower");

    Vector_ref<Graph_lib::Rectangle> squares;
    const int side = 100;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            Graph_lib::Rectangle* r = new Graph_lib::Rectangle(Point(i * side, j * side), side, side);
            if (i == j)
                r->set_fill_color(Color::red);
            squares.push_back(r);
            win.attach(*r);
        }

    Image skeleton1(Point(6 * side, 0), "img/skeleton.jpg");
    Image skeleton2(Point(0, 4 * side), "img/skeleton.jpg");
    Image skeleton3(Point(4 * side, 6 * side), "img/skeleton.jpg");
    win.attach(skeleton1);
    win.attach(skeleton2);
    win.attach(skeleton3);

    Image warrior(Point(0, 0), "img/warrior.jpg");
    win.attach(warrior);

    bool is_blank[8][8] = {
        {false, true, true, true, true, true, false, false},
        {true, false, true, true, true, true, false, false},
        {true, true, false, true, true, true, true, true},
        {true, true, true, false, true, true, true, true},
        {false, false, true, true, false, true, true, true},
        {false, false, true, true, true, false, true, true},
        {true, true, true, true, false, false, false, true},
        {true, true, true, true, false, false, true, false}
    };
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (is_blank[i][j]) {
                warrior.move(j * side - warrior.point(0).x, i * side - warrior.point(0).y);
                win.wait_for_button();
            }
    return 0;
}
