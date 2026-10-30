#ifndef FRONT_WING_CPP
#define FRONT_WING_CPP

#include "front_wing.h"
#include "miniwin.h"

FrontWing::FrontWing(int x, int y)
    : Shape(x, y, miniwin::AMARILLO),
      left(x, y - 24, 16, miniwin::AMARILLO),
      right(x, y + 24, 16, miniwin::AMARILLO) {}

void FrontWing::draw() {
    left.draw();
    right.draw();
}

void FrontWing::erase() {
    left.erase();
    right.erase();
}

void FrontWing::moveTo(int nx, int ny) {
    erase();

    x = nx;
    y = ny;

    left = Square(x, y - 24, 16, miniwin::AMARILLO);
    right = Square(x, y + 24, 16, miniwin::AMARILLO);
    draw();
}

#endif
