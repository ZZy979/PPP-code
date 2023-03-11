#include "Graph.h"
#include "Simple_window.h"
#include "exec14_graph.h"

using namespace Graph_lib;

// draw a smiley face and a frowny face
int main() {
    Simple_window win(Point(100, 100), 600, 400, "smiley and frowny faces");

    Smiley smiley(Point(100, 100), 80);
    smiley.set_fill_color(Color::yellow);
    smiley.set_style(Line_style(Line_style::solid, 5));
    win.attach(smiley);

    Frowny frowny(Point(300, 100), 80);
    frowny.set_fill_color(Color::red);
    frowny.set_style(Line_style(Line_style::solid, 5));
    win.attach(frowny);

    SmileyWithHat smiley_with_hat(Point(100, 300), 60);
    smiley_with_hat.set_color(Color::dark_green);
    smiley_with_hat.set_fill_color(Color::green);
    smiley_with_hat.set_style(Line_style(Line_style::solid, 5));
    win.attach(smiley_with_hat);

    FrownyWithHat frowny_with_hat(Point(300, 300), 60);
    frowny_with_hat.set_color(Color::dark_blue);
    frowny_with_hat.set_fill_color(Color::blue);
    frowny_with_hat.set_style(Line_style(Line_style::solid, 5));
    win.attach(frowny_with_hat);

    win.wait_for_button();

    smiley.move(200, 0);
    frowny.move(0, 200);
    frowny_with_hat.move(-200, 0);
    smiley_with_hat.move(0, -200);
    win.set_label("smiley and frowny faces after moving");
    win.wait_for_button();
    return 0;
}
