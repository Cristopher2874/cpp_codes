#ifndef SQUARE_CPP
#define SQUARE_CPP

#include "square.h"
#include "miniwin.h"

Square::Square(int x, int y, int side, int shape_color, bool fill)
    : Shape(x, y, shape_color, fill), side(side) {
}

void Square::draw() {
    miniwin::color(shape_color);
    int left = x - side / 2;
    int top = y - side / 2;
    int right = x + side / 2;
    int bottom = y + side / 2;

    if (fill) {
        miniwin::rectangulo_lleno(left, top, right, bottom);
    } else {
        miniwin::rectangulo(left, top, right, bottom);
    }
}

void Square::erase() {
    miniwin::color(miniwin::NEGRO);
    int left = x - side / 2;
    int top = y - side / 2;
    int right = x + side / 2;
    int bottom = y + side / 2;

    if (fill) {
        miniwin::rectangulo_lleno(left, top, right, bottom);
    } else {
        miniwin::rectangulo(left, top, right, bottom);
    }
}

#endif