#include "GUI.h"
#include "Window.h"

#include "ch12/exec12_graph.h"

using namespace Graph_lib;

class Shapes_window : public Graph_lib::Window {
public:
    Shapes_window(Point xy, int w, int h, const string& title)
            :Graph_lib::Window(xy, w, h, title),
            x_input(Point(x_max() - 340, 0), 50, 20, "x"),
            y_input(Point(x_max() - 240, 0), 50, 20, "y"),
            shapes_menu(Point(x_max() - 180, 0), 100, 20, Menu::vertical, "shapes"),
            quit_button(Point(x_max() - 70, 0), 70, 20, "Quit",
                    [](Address, Address pw) { reference_to<Shapes_window>(pw).quit(); }) {
        attach(x_input);
        attach(y_input);

        shapes_menu.attach(new Button(Point(0, 0), 0, 0, "circle",
                [](Address, Address pw) { reference_to<Shapes_window>(pw).draw_circle(); }));
        shapes_menu.attach(new Button(Point(0, 0), 0, 0, "triangle",
                [](Address, Address pw) { reference_to<Shapes_window>(pw).draw_triangle(); }));
        shapes_menu.attach(new Button(Point(0, 0), 0, 0, "square",
                [](Address, Address pw) { reference_to<Shapes_window>(pw).draw_square(); }));
        shapes_menu.attach(new Button(Point(0, 0), 0, 0, "hexagon",
                [](Address, Address pw) { reference_to<Shapes_window>(pw).draw_hexagon(); }));
        attach(shapes_menu);
        attach(quit_button);
    }

private:
    Point get_point() { return Point(x_input.get_int(), y_input.get_int()); }

    void draw_shape(Shape* p) {
        shapes.push_back(p);
        attach(*p);
        redraw();
    }

    void draw_circle() { draw_shape(new Circle(get_point(), 50)); }
    void draw_triangle() { draw_shape(new Regular_polygon(get_point(), 50, 3, 90)); }
    void draw_square() { draw_shape(new Regular_polygon(get_point(), 50, 4, 45)); }
    void draw_hexagon() { draw_shape(new Regular_polygon(get_point(), 50, 6)); }
    void quit() { hide(); }

    Vector_ref<Shape> shapes;

    In_box x_input, y_input;
    Menu shapes_menu;
    Button quit_button;
};

int main() {
    Shapes_window win(Point(100, 100), 600, 400, "Draw shapes");
    return gui_main();
}
