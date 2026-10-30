#ifndef SHAPE_CPP
#define SHAPE_CPP

#include "shape.h"

Shape::Shape(int x, int y, int shape_color, bool fill) {
    this->x = x;
    this->y = y;
    this->shape_color = shape_color;
    this->fill = fill;
}

Shape::~Shape(){}

void Shape::moveTo(int nx, int ny) {
    erase();
    x = nx;
    y = ny;
    draw();
}

#endif