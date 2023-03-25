#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "Simple_window.h"
#include "exec15_graph.h"

using namespace Graph_lib;
using namespace std;

// display people height data as a bar graph
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs)
        error("can't open ", argv[1]);

    string title;
    vector<string> people_height;
    vector<double> number_of_people;
    getline(ifs, title);
    for (pair<string, double> p; ifs >> p.first >> p.second;) {
        people_height.push_back(p.first);
        number_of_people.push_back(p.second);
    }

    Graph_lib::Window win(Point(100, 100), 600, 400, title);

    BarGraph graph(Point(50, 50), 500, 300, number_of_people, people_height, title, 0, 30);
    graph.set_fill_color(Color::blue);
    win.attach(graph);

    gui_main();
    return 0;
}
