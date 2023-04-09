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
    Button menu_button;

    // actions invoked by callbacks:
    void change(Color c) { lines.set_color(c); }
    void hide_menu() { color_menu.hide(); menu_button.show(); }
    void red_pressed() { change(Color::red); hide_menu(); }
    void blue_pressed() { change(Color::blue); hide_menu(); }
    void black_pressed() { change(Color::black); hide_menu(); }
    void menu_pressed() { menu_button.hide(); color_menu.show(); }
    void next();
    void quit();
};

}
