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

// hacemos los incrementos para que la animación sea fluída y no solo constante
// un poco más de cálculos dependiendo del vecotr de velocidad.
void Shape::moveBy(int dx, int dy) {
    moveTo(x + dx, y + dy);
}

#endif