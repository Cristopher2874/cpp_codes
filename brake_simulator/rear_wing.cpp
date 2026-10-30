#ifndef REAR_WING_CPP
#define REAR_WING_CPP

#include "rear_wing.h"
#include "miniwin.h"

RearWing::RearWing(int x, int y)
    : Shape(x, y, miniwin::MAGENTA),
      left(x, y - 24, 20, miniwin::MAGENTA),
      right(x, y + 24, 20, miniwin::MAGENTA) {}

void RearWing::draw() {
    left.draw();
    right.draw();
}

void RearWing::erase() {
    left.erase();
    right.erase();
}

void RearWing::moveTo(int nx, int ny) {
    erase();

    x = nx;
    y = ny;

    left = Square(x, y - 24, 20, miniwin::MAGENTA);
    right = Square(x, y + 24, 20, miniwin::MAGENTA);
    draw();
}

#endif
