#include <sstream>

#include "GUI.h"
#include "Window.h"

#include "ch07/calculator_v2/lexer.h"
#include "ch07/calculator_v2/parser.h"

using namespace Graph_lib;

class Calculator_window : public Graph_lib::Window {
public:
    Calculator_window(Point xy, int w, int h, const string& title)
            :Graph_lib::Window(xy, w, h, title),
            ts(iss),
            parser(ts),
            expr_input(Point(100, 10), w - 200, 20, "Expression:"),
            result_output(Point(100, 40), w - 200, 20, "Result:"),
            calculate_button(Point(w - 80, 10), 70, 20, "=",
                    [](Address, Address pw) { reference_to<Calculator_window>(pw).calculate(); }),
            quit_button(Point(w - 80, 40), 70, 20, "Quit",
                    [](Address, Address pw) { reference_to<Calculator_window>(pw).quit(); }) {
        attach(expr_input);
        attach(result_output);
        attach(calculate_button);
        attach(quit_button);
    }

private:
    void calculate() {
        iss.clear();
        iss.str(expr_input.get_string() + ";");
        ts.ignore();

        std::ostringstream oss;
        try {
            oss << parser.statement();
        }
        catch (std::exception& e) {
            oss << "error: " << e.what();
        }
        result_output.put(oss.str());
    }

    void quit() { hide(); }

    std::istringstream iss;
    Token_stream ts;
    Parser parser;

    In_box expr_input;
    Out_box result_output;
    Button calculate_button;
    Button quit_button;
};

// Simple calculator - GUI version
int main() {
    Calculator_window win(Point(100, 100), 400, 70, "Simple calculator");
    return gui_main();
}
