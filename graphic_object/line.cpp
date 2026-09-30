#ifndef LINE_CPP
#define LINE_CPP

#include "line.h"
#include "miniwin.h"

Line::Line(int x1, int y1, int x2, int y2, int shape_color)
    : Shape(x1, y1, shape_color, false) {
    this->x2 = x2;
    this->y2 = y2;
}

void Line::draw() {
    miniwin::color(shape_color);
    miniwin::linea(x, y, x2, y2);
}

void Line::erase() {
    miniwin::color(miniwin::NEGRO);
    miniwin::linea(x, y, x2, y2);
}

#endif