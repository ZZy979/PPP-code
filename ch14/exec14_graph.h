#pragma once

#include "Graph.h"
#include "ch12/exec12_graph.h"
#include "ch13/exec13_graph.h"

// 第14章习题中的自定义形状类
namespace Graph_lib {

// 有两只眼睛和一张嘴的脸
struct Face : Circle {
    Face(Point center, int radius, bool smiley)
            :Circle(center, radius),
            left_eye(Point(center.x - 2 * radius / 5, smiley ? center.y - radius / 5 : center.y - 2 * radius / 5),
                    radius / 5, smiley ? 0 : 180, smiley ? 180 : 360),
            right_eye(Point(center.x + 2 * radius / 5, smiley ? center.y - radius / 5 : center.y - 2 * radius / 5),
                    radius / 5, smiley ? 0 : 180, smiley ? 180 : 360),
            mouth(Point(center.x, smiley ? center.y + radius / 5 : center.y + 3 * radius / 5),
                    2 * radius / 5, smiley ? 180 : 0, smiley ? 360 : 180) {}

    void set_color(Color color);
    void set_style(Line_style style);
    void draw_lines() const override;
    void move(int dx, int dy) override;

private:
    Arc left_eye, right_eye, mouth;
};

// 笑脸
struct Smiley : Face {
    Smiley(Point center, int radius) :Face(center, radius, true) {}
};

// 哭脸
struct Frowny : Face {
    Frowny(Point center, int radius) :Face(center, radius, false) {}
};

// 简单的帽子
struct Hat : Rectangle {
    Hat(Point top_left, int width, int height, int brim_width);
    void set_color(Color color);
    void set_style(Line_style style);
    void draw_lines() const override;
    void move(int dx, int dy) override;

private:
    Line brim;
};

// 戴帽子的脸
struct FaceWithHat : Face {
    FaceWithHat(Point center, int radius, bool smiley)
            :Face(center, radius, smiley),
            hat(Point(center.x - 3 * radius / 5, center.y - 7 * radius / 5),
                    6 * radius / 5, 3 * radius / 5, 2 * radius / 5) {}
    void set_color(Color color);
    void set_style(Line_style style);
    void draw_lines() const override;
    void move(int dx, int dy) override;

private:
    Hat hat;
};

// 戴帽子的笑脸
struct SmileyWithHat : FaceWithHat {
    SmileyWithHat(Point center, int radius) :FaceWithHat(center, radius, true) {}
};

// 戴帽子的哭脸
struct FrownyWithHat : FaceWithHat {
    FrownyWithHat(Point center, int radius) :FaceWithHat(center, radius, false) {}
};

// 二叉树
class Binary_tree : public Shape {
public:
    Binary_tree(Point root, int levels, int height, int distance);

    int levels() const { return levels_; }
    void set_levels(int levels) { levels_ = levels; }

    int height() const { return height_; }
    void set_height(int height) { height_ = height; }

    int distance() const { return distance_; }
    void set_distance(int distance) { distance_ = distance; }

protected:
    void draw_lines() const override;
    void draw_tree(Point root, int level) const;
    virtual void draw_node(Point p) const;
    virtual void draw_line(Point parent, Point child) const;

private:
    int levels_;
    int height_;
    int distance_;
};

// 圆形节点的二叉树
class Circle_node_binary_tree : public Binary_tree {
public:
    Circle_node_binary_tree(Point root, int levels, int height, int distance, int node_radius);

    int node_radius() const { return node_radius_; }
    void set_node_radius(int node_radius) { node_radius_ = node_radius; }

protected:
    void draw_node(Point p) const override;

private:
    int node_radius_;
};

// 三角形节点的二叉树
class Triangle_node_binary_tree : public Binary_tree {
public:
    Triangle_node_binary_tree(Point root, int levels, int height, int distance, int node_side);

    int node_side() const { return node_side_; }
    void set_node_side(int node_side) { node_side_ = node_side; }

protected:
    void draw_node(Point p) const override;

private:
    int node_side_;
};

// 箭头连线的二叉树
class Arrow_line_binary_tree : public Binary_tree {
public:
    using Binary_tree::Binary_tree;

protected:
    void draw_node(Point p) const override {}
    void draw_line(Point parent, Point child) const override;
};

}
