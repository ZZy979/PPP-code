#include <string>

#include "Graph.h"
#include "Simple_window.h"
#include "exec14_graph.h"

using namespace Graph_lib;

// draw a binary_tree
int main() {
    Simple_window win(Point(100, 100), 1000, 300, "binary tree");

    Binary_tree binary_tree(Point(500, 50), 0, 50, 50);
    win.attach(binary_tree);
    for (int levels = 0; levels <= 5; ++levels) {
        binary_tree.set_levels(levels);
        win.set_label("binary tree (levels = " + to_string(levels) + ")");
        win.wait_for_button();
    }
    win.detach(binary_tree);

    Circle_node_binary_tree circle_node_binary_tree(Point(500, 50), 5, 50, 50, 10);
    circle_node_binary_tree.set_color(Color::red);
    circle_node_binary_tree.set_fill_color(Color::red);
    win.attach(circle_node_binary_tree);
    win.set_label("circle-node binary tree");
    win.wait_for_button();
    win.detach(circle_node_binary_tree);

    Triangle_node_binary_tree triangle_node_binary_tree(Point(500, 50), 5, 50, 50, 10);
    triangle_node_binary_tree.set_color(Color::green);
    triangle_node_binary_tree.set_style(Line_style(Line_style::solid, 3));
    triangle_node_binary_tree.set_fill_color(Color::green);
    win.attach(triangle_node_binary_tree);
    win.set_label("triangle-node binary tree");
    win.wait_for_button();
    win.detach(triangle_node_binary_tree);

    Arrow_line_binary_tree arrow_line_binary_tree(Point(500, 50), 5, 50, 50);
    arrow_line_binary_tree.set_color(Color::blue);
    arrow_line_binary_tree.set_fill_color(Color::blue);
    win.attach(arrow_line_binary_tree);
    win.set_label("arrow-line binary tree");
    win.wait_for_button();
    win.detach(arrow_line_binary_tree);
    return 0;
}
