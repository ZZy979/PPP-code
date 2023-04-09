#include <FL/Fl.H>
#include <FL/Fl_Round_Clock.H>
#include <FL/Fl_Window.H>

// analog clock
int main(int argc, char* argv[]) {
    Fl_Window* window = new Fl_Window(220, 220, "Clock");
    Fl_Round_Clock* clock = new Fl_Round_Clock(10, 10, 200, 200);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}
