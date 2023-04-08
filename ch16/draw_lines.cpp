#include "GUI.h"
#include "lines_window.h"

using namespace Graph_lib;

// A simple application that allows user to display a sequence of lines specified as a sequence of coordinate pairs
int main() {
    Lines_window win(Point(100, 100), 600, 400, "lines");
    return gui_main();
}
