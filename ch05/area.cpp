#include "area.h"

// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area(int length, int width) {
    if (length <= 0 || width <= 0)
        throw Bad_area();
    return length * width;
}

const int frame_width = 2;

// calculate area within frame
int framed_area(int x, int y) {
    return area(x - frame_width, y - frame_width);
}
