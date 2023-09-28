#include <FL/Fl.H>

#include "word_query_window.h"

int main() {
    Word_query_window* win = new Word_query_window(800, 600, "Word Query");
    win->show();
    return Fl::run();
}
