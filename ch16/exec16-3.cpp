#include <random>

#include "GUI.h"
#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

inline int rand_int(int min, int max) {
    static default_random_engine ran;
    return uniform_int_distribution<>(min, max)(ran);
}

class My_window : public Graph_lib::Window {
public:
    My_window(Point xy, int w, int h, const string& title)
            :Graph_lib::Window(xy, w, h, title),
            button(Point(x_max() / 2 - 25, y_max() / 2 - 25), 50, 50, "",
                    [](Address, Address pw) { reference_to<My_window>(pw).move_image_button(); }),
            image(Point(x_max() / 2 - 6, y_max() / 2 - 6), "img/blue-ball.gif") {
        attach(button);
        attach(image);
    }

    void move_image_button() {
        int x = rand_int(0, x_max() - 25), y = rand_int(0, y_max() - 25);
        int dx = x - button.loc.x, dy = y - button.loc.y;
        button.move(dx, dy);
        image.move(dx, dy);
    }
private:
    Button button;
    Image image;
};

int main() {
    My_window win(Point(100, 100), 600, 400, "Moving image button");
    return gui_main();
}
