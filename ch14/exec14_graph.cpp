#include "exec14_graph.h"

namespace Graph_lib {

void Face::set_color(Color color) {
    Shape::set_color(color);
    left_eye.set_color(color);
    right_eye.set_color(color);
    mouth.set_color(color);
}

void Face::set_style(Line_style style) {
    Shape::set_style(style);
    left_eye.set_style(style);
    right_eye.set_style(style);
    mouth.set_style(style);
}

void Face::draw_lines() const {
    Circle::draw_lines();
    left_eye.draw_lines();
    right_eye.draw_lines();
    mouth.draw_lines();
}

void Face::move(int dx, int dy) {
    Shape::move(dx, dy);
    left_eye.move(dx, dy);
    right_eye.move(dx, dy);
    mouth.move(dx, dy);
}

Hat::Hat(Point top_left, int width, int height, int brim_width)
        :Rectangle(top_left, width, height),
        brim(Point(top_left.x - brim_width, top_left.y + height),
                Point(top_left.x + width + brim_width, top_left.y + height)) {
    if (brim_width <= 0)
        error("Bad hat: invalid brim width");
    set_fill_color(color());
}

void Hat::set_color(Color color) {
    Shape::set_color(color);
    set_fill_color(color);
    brim.set_color(color);
}

void Hat::set_style(Line_style style) {
    Shape::set_style(style);
    brim.set_style(style);
}

void Hat::draw_lines() const {
    Rectangle::draw_lines();
    brim.draw();
}

void Hat::move(int dx, int dy) {
    Shape::move(dx, dy);
    brim.move(dx, dy);
}

void FaceWithHat::set_color(Color color) {
    Face::set_color(color);
    hat.set_color(color);
}

void FaceWithHat::set_style(Line_style style) {
    Face::set_style(style);
    hat.set_style(style);
}

void FaceWithHat::draw_lines() const {
    Face::draw_lines();
    hat.draw();
}

void FaceWithHat::move(int dx, int dy) {
    Face::move(dx, dy);
    hat.move(dx, dy);
}

Binary_tree::Binary_tree(Point root, int levels, int height, int distance)
        :levels_(levels), height_(height), distance_(distance) {
    if (levels < 0 || height <= 0 || distance <= 0)
        error("Bad binary tree: must have levels >= 0, height > 0 and distance > 0");
    add(root);
}

void Binary_tree::draw_lines() const {
    draw_tree(point(0), levels_);
}

void Binary_tree::draw_tree(Point root, int level) const {
    if (level == 0)
        return;

    draw_node(root);
    if (level >= 2) {
        int d = (1 << (level - 2)) * distance_ / 2;
        Point left(root.x - d, root.y + height_), right(root.x + d, root.y + height_);
        draw_line(root, left);
        draw_line(root, right);
        draw_tree(left, level - 1);
        draw_tree(right, level - 1);
    }
}

void Binary_tree::draw_node(Point p) const {
    Mark(p, 'o').draw();
}

void Binary_tree::draw_line(Point parent, Point child) const {
    Line line(parent, child);
    line.set_color(color());
    line.set_style(style());
    line.draw();
}

Circle_node_binary_tree::Circle_node_binary_tree(
        Point root, int levels, int height, int distance, int node_radius)
        :Binary_tree(root, levels, height, distance), node_radius_(node_radius) {
    if (node_radius <= 0)
        error("Bad Circle_node_binary_tree: invalid node radius");
}

void Circle_node_binary_tree::draw_node(Point p) const {
    Circle circle(p, node_radius_);
    circle.set_color(color());
    circle.set_style(style());
    circle.set_fill_color(fill_color());
    circle.draw();
}

Triangle_node_binary_tree::Triangle_node_binary_tree(
        Point root, int levels, int height, int distance, int node_side)
        :Binary_tree(root, levels, height, distance), node_side_(node_side) {
    if (node_side <= 0)
        error("Bad Triangle_node_binary_tree: invalid node side");
}

void Triangle_node_binary_tree::draw_node(Point p) const {
    const double sqrt3 = sqrt(3);
    Polygon triangle;
    triangle.add(Point(p.x, p.y - sqrt3 / 3 * node_side_));
    triangle.add(Point(p.x - node_side_ / 2, p.y + sqrt3 / 6 * node_side_));
    triangle.add(Point(p.x + node_side_ / 2, p.y + sqrt3 / 6 * node_side_));
    triangle.set_color(color());
    triangle.set_style(style());
    triangle.set_fill_color(fill_color());
    triangle.draw();
}

void Arrow_line_binary_tree::draw_line(Point parent, Point child) const {
    Arrow arrow(parent, child);
    arrow.set_color(color());
    arrow.draw();
}

}
