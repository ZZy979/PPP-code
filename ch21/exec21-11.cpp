#include <FL/Fl.H>

#include "order_list_window.h"

int main() {
    Order_list_window* win = new Order_list_window(800, 600, "Order Management");
    win->show();
    return Fl::run();
}
