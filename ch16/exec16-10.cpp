#include <cmath>
#include <string>

#include "GUI.h"
#include "Graph.h"
#include "Window.h"

#include "ch15/exec15_graph.h"

using namespace Graph_lib;

struct Function_setting {
    Fct* f;
    string label;
    double r1 = -15;
    double r2 = 15;
} settings[] = {
    {sqrt, "y = sqrt(x)", 0, 15},
    {exp, "y = e^x"},
    {log, "y = ln x", 0, 15},
    {sin, "y = sin x"},
    {cos, "y = cos x"},
    {tan, "y = tan x"},
};

class Function_graphing_window : public Graph_lib::Window {
public:
    Function_graphing_window(Point xy, int w, int h, const string& title)
            :Graph_lib::Window(xy, w, h, title),
            x(Axis::x, Point(0, h / 2), w, w / 20),
            y(Axis::y, Point(w / 2, h), h, h / 20),
            fct(sin, -15, 15, Point(w / 2, h / 2), 400, 20, 20),
            label(Point(50, 50), "y = sin x"),
            function_menu(Point(w - 80, 0), 80, 20, Menu::vertical, "function") {
        attach(x);
        attach(y);
        attach(fct);
        attach(label);

        function_menu.attach(new Button(Point(0, 0), 0, 0, "sqrt",
                [](Address, Address pw) { reference_to<Function_graphing_window>(pw).graph_function(settings[0]); }));
        function_menu.attach(new Button(Point(0, 0), 0, 0, "exp",
                [](Address, Address pw) { reference_to<Function_graphing_window>(pw).graph_function(settings[1]); }));
        function_menu.attach(new Button(Point(0, 0), 0, 0, "log",
                [](Address, Address pw) { reference_to<Function_graphing_window>(pw).graph_function(settings[2]); }));
        function_menu.attach(new Button(Point(0, 0), 0, 0, "sin",
                [](Address, Address pw) { reference_to<Function_graphing_window>(pw).graph_function(settings[3]); }));
        function_menu.attach(new Button(Point(0, 0), 0, 0, "cos",
                [](Address, Address pw) { reference_to<Function_graphing_window>(pw).graph_function(settings[4]); }));
        function_menu.attach(new Button(Point(0, 0), 0, 0, "tan",
                [](Address, Address pw) { reference_to<Function_graphing_window>(pw).graph_function(settings[5]); }));
        attach(function_menu);
    }

private:
    void graph_function(const Function_setting& s) {
        fct.set_function(s.f);
        fct.set_range(s.r1, s.r2);
        label.set_label(s.label);
        redraw();
    }

    Axis x, y;
    ResettableFunction fct;
    Text label;

    Menu function_menu;
};

int main() {
    Function_graphing_window win(Point(100, 100), 600, 400, "Function graphing");
    return gui_main();
}
