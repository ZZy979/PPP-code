#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

istream& operator>>(istream& is, Point& p);
ostream& operator<<(ostream& os, const Point& p);
void read_points(istream& is, vector<Point>& points);
void print_points(ostream& os, const vector<Point>& points);
bool operator==(const Point& p, const Point& q);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " filename\n";
        return 0;
    }

    try {
        vector<Point> original_points;
        cout << "Please input seven (x,y) points:\n";
        read_points(cin, original_points);
        print_points(cout, original_points);

        string filename = argv[1];
        ofstream ofs(filename);
        if (!ofs)
            throw runtime_error("can't open output file " + filename);
        print_points(ofs, original_points);
        ofs.close();

        ifstream ifs(filename);
        if (!ifs)
            throw runtime_error("can't open input file " + filename);
        vector<Point> processed_points;
        read_points(ifs, processed_points);
        print_points(cout, processed_points);

        if (original_points != processed_points)
            cout << "Something's wrong!\n";
        return 0;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
}

istream& operator>>(istream& is, Point& p) {
    char ch1;
    is >> ch1;
    if (!is || ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    int x, y;
    char ch2, ch3;
    is >> x >> ch2 >> y >> ch3;
    if (!is || ch2 != ',' || ch3 != ')')
        throw runtime_error("bad point");
    p = {x, y};
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    return os << '(' << p.x << ',' << p.y << ')';
}

void read_points(istream& is, vector<Point>& points) {
    for (Point p; is >> p;)
        points.push_back(p);
}

void print_points(ostream& os, const vector<Point>& points) {
    for (const Point& p : points)
        os << p << endl;
}

bool operator==(const Point& p, const Point& q) {
    return p.x == q.x && p.y == q.y;
}
