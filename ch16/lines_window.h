#pragma once

#include <string>

#include "GUI.h"

namespace Graph_lib {

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    // data:
    Open_polyline lines;

    // widgets:
    Button next_button;     // add (next_x,next_y) to lines
    Button quit_button;     // end program
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button color_menu_button;
    Menu line_style_menu;
    Button line_style_menu_button;

    // actions invoked by callbacks:
    void change_color(Color c) { lines.set_color(c); }
    void hide_color_menu() { color_menu.hide(); color_menu_button.show(); }
    void red_pressed() { change_color(Color::red); hide_color_menu(); }
    void blue_pressed() { change_color(Color::blue); hide_color_menu(); }
    void black_pressed() { change_color(Color::black); hide_color_menu(); }
    void color_menu_pressed() { color_menu_button.hide(); color_menu.show(); }

    void change_line_style(Line_style style) { lines.set_style(style); }
    void hide_line_style_menu() { line_style_menu.hide(); line_style_menu_button.show(); }
    void solid_pressed() { change_line_style(Line_style::solid); hide_line_style_menu(); }
    void dash_pressed() { change_line_style(Line_style::dash); hide_line_style_menu(); }
    void dot_pressed() { change_line_style(Line_style::dot); hide_line_style_menu(); }
    void line_style_menu_pressed() { line_style_menu_button.hide(); line_style_menu.show(); }

    void next();
    void quit();
};

}
