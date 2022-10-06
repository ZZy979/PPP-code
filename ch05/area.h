#pragma once

// a type specifically for reporting errors from area()
class Bad_area {};

int area(int length, int width);
extern const int frame_width;
int framed_area(int x, int y);
