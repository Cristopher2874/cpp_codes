#ifndef SHAPE_CPP
#define SHAPE_CPP

#include "shape.h"

Shape::Shape(int x, int y, int shape_color, bool fill)
    : x(x), y(y), shape_color(shape_color), fill(fill) {
}

Shape::~Shape() {
}

#endif