#ifndef WHEEL_CPP
#define WHEEL_CPP

#include "wheel.h"
#include "miniwin.h"

Wheel::Wheel(int width, int x, int y, int side)
    : Shape(x, y, miniwin::CYAN, false), 
    width(width),
    side(side)
    {}

void Wheel::draw() {
    current_wheel.draw();
}

void Wheel::erase() {
    current_wheel.erase();
}

#endif