#include "controller.h"

void Test_controller::on() {
    on_ = true;
}

void Test_controller::off() {
    on_ = false;
}

void Test_controller::set_level(int level) {
    level_ = level;
}

std::string Test_controller::show() const {
    return on_ ? std::to_string(level_) : "off";
}

void Line_color_controller::on() {
    if (!shape_.color().visibility()) {
        Graph_lib::Color color = shape_.color();
        color.set_visibility(Graph_lib::Color::visible);
        shape_.set_color(color);
    }
}

void Line_color_controller::off() {
    if (shape_.color().visibility()) {
        Graph_lib::Color color = shape_.color();
        color.set_visibility(Graph_lib::Color::invisible);
        shape_.set_color(color);
    }
}

void Line_color_controller::set_level(int level) {
    shape_.set_color(level);
}

std::string Line_color_controller::show() const {
    return shape_.color().visibility() ? std::to_string(shape_.color().as_int()) : "invisible";
}
