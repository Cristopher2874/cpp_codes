#ifndef WHEEL_CPP
#define WHEEL_CPP

#include "wheel.h"
#include "miniwin.h"

Wheel::Wheel(int width, int x, int y, int side)
    : Shape(x, y, miniwin::CYAN, true),
      width(width),
      current_wheel(x, y, width, miniwin::CYAN, true) {}

void Wheel::draw() {
    current_wheel.draw();
}

void Wheel::erase() {
    current_wheel.erase();
}

void Wheel::moveTo(int nx, int ny) {
    erase();

    x = nx;
    y = ny;

    current_wheel = Square(x, y, width, miniwin::CYAN, true);
    draw();
}

void Wheel::moveBy(int dx, int dy) {
    erase();

    current_wheel.moveBy(dx, dy);

    draw();
}

#endif
