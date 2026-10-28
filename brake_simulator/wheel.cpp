#include "wheel.h"
#include "miniwin.h"

Wheel::Wheel(int width, int x, int y, int side)
    : Shape(x, y, miniwin::CYAN, true),
      width(width),
      current_wheel(x, y, side > 0 ? side : width, miniwin::CYAN, true) {}

void Wheel::draw() {
    current_wheel.draw();
}

void Wheel::erase() {
    current_wheel.erase();
}
