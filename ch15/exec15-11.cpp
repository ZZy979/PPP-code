#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Graph.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

struct Temperature {
    int month;
    vector<int> data;
};

istream& operator>>(istream& is, Temperature& t);

// data value to coordinate conversion
class Scale {
    int cbase;  // coordinate base
    int vbase;  // base of values
    double scale;

public:
    Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) {}
    int operator()(int v) const { return cbase + (v - vbase) * scale; }
};

// 北京、黑龙江和广东每个月的日均最高温度
// 数据来源：https://www.tianqi.com/qiwen/china/
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file\n";
        return 0;
    }

    ifstream ifs(argv[1]);
    if (!ifs)
        error("can't open ", argv[1]);

    // MSVC不支持中文字符串常量（error C2001: 常量中有换行符），在结尾添加空格以绕过编译错误
    Graph_lib::Window win(Point(100, 100), 600, 450, "不同省份每个月的日均最高温度 ");

    const Point origin(50, 400);
    constexpr int font_size = 14;

    const int min_temp = -20, max_temp = 35, step = 5;
    const int x_length = 480, y_length = 360;
    const int x_ticks = 12, y_ticks = (max_temp - min_temp) / step + 1;
    Axis x_axis(Axis::x, origin, x_length, x_ticks, "月份");
    x_axis.label.set_font_size(font_size);
    x_axis.label.move(400, 0);
    Axis y_axis(Axis::y, origin, y_length, y_ticks, "日均最高温度(℃)");
    y_axis.label.set_font_size(font_size);
    win.attach(x_axis);
    win.attach(y_axis);

    Scale xs(origin.x, 0, x_length / x_ticks);
    Scale ys(origin.y, min_temp, -y_length / (max_temp - min_temp));

    Vector_ref<Text> x_labels, y_labels;
    for (int i = 1; i <= x_ticks; ++i) {
        Text* x_label = new Text(Point(xs(i) - 5, origin.y + 20), to_string(i));
        x_label->set_font_size(font_size);
        x_labels.push_back(x_label);
        win.attach(*x_label);
    }
    for (int t = min_temp; t <= max_temp; t += step) {
        Text* y_label = new Text(Point(origin.x - 25, ys(t) + 5), to_string(t));
        y_label->set_font_size(font_size);
        y_labels.push_back(y_label);
        win.attach(*y_label);
    }

    Vector_ref<Open_polyline> lines(new Open_polyline, new Open_polyline, new Open_polyline);
    for (Temperature t; ifs >> t; t.data.clear()) {
        int x = xs(t.month);
        for (int i = 0; i < lines.size(); ++i)
            lines[i].add(Point(x, ys(t.data[i])));
    }

    vector<Color> colors{Color::dark_green, Color::blue, Color::red};
    for (int i = 0; i < lines.size(); ++i) {
        lines[i].set_color(colors[i]);
        win.attach(lines[i]);
    }

    Vector_ref<Text> legends;
    vector<string> labels{"北京", "黑龙江 ", "广东"};
    for (int i = 0; i < lines.size(); ++i) {
        Text* legend = new Text(Point(500, (i + 1) * 20), labels[i]);
        legend->set_color(lines[i].color());
        legend->set_font_size(font_size);
        legends.push_back(legend);
        win.attach(*legend);
    }

    gui_main();
    return 0;
}

istream& operator>>(istream& is, Temperature& t) {
    string line;
    if (!getline(is, line))
        return is;

    istringstream iss(line);
    iss >> t.month;
    for (int temp; iss >> temp;)
        t.data.push_back(temp);
    return is;
}
