#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

// draw images
int main() {
    Simple_window win(Point(100, 100), 600, 400, "Images: Rita 9/21/05 4pm CDT Wednesday");

    Image rita(Point(0, 0), "img/rita.jpg");
    Image path(Point(0, 0), "img/rita_path.gif");
    path.set_mask(Point(50, 250), 600, 400);    // select likely landfall

    win.attach(path);
    win.attach(rita);
    win.wait_for_button();
    return 0;
}
