#ifndef CHASSIS_CPP
#define CHASSIS_CPP

#include "chassis.h"
#include "miniwin.h"

Chassis::Chassis(int x, int y, int side)
    : Shape(x, y, miniwin::AZUL),
      side(side),
      body(x, y, side, miniwin::AZUL) {}

void Chassis::draw() {
    body.draw();
}

void Chassis::erase() {
    body.erase();
}

void Chassis::moveTo(int nx, int ny) {
    erase();

    x = nx;
    y = ny;

    body = Square(x, y, side, miniwin::AZUL);
    draw();
}

#endif
