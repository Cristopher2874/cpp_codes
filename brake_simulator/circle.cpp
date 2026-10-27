#ifndef CIRCLE_CPP
#define CIRCLE_CPP

#include "circle.h"
#include "miniwin.h"

Circle::Circle(int x, int y, int radius, int shape_color, bool fill)
    : Shape(x, y, shape_color, fill) {
    this->radius = radius;
}

void Circle::draw() {
    miniwin::color(shape_color);
    if (fill)
        miniwin::circulo_lleno(x, y, radius);
    else
        miniwin::circulo(x, y, radius);
}

void Circle::erase() {
    miniwin::color(miniwin::NEGRO);
    if (fill)
        miniwin::circulo_lleno(x, y, radius);
    else
        miniwin::circulo(x, y, radius);
}

#endif
