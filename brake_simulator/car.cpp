#ifndef CAR_CPP
#define CAR_CPP

#include "car.h"

Car::Car(int x, int y, int wheel_width, int wheel_side) : Shape(x, y, miniwin::AZUL),
      front_left_wheel(wheel_width, x - 60, y - 45, wheel_side),
      front_right_wheel(wheel_width, x + 60, y - 45, wheel_side),
      rear_left_wheel(wheel_width, x - 60, y + 45, wheel_side),
      rear_right_wheel(wheel_width, x + 60, y + 45, wheel_side) {}

void Car::draw() {
    front_left_wheel.draw();
    front_right_wheel.draw();
    rear_left_wheel.draw();
    rear_right_wheel.draw();
}

void Car::erase() {
    front_left_wheel.erase();
    front_right_wheel.erase();
    rear_left_wheel.erase();
    rear_right_wheel.erase();
}

void Car::moveTo(int nx, int ny) {
    erase();

    int dx = nx - x;
    int dy = ny - y;
    x = nx;
    y = ny;

    front_left_wheel.moveBy(dx, dy);
    front_right_wheel.moveBy(dx, dy);
    rear_left_wheel.moveBy(dx, dy);
    rear_right_wheel.moveBy(dx, dy);

    draw();
}

void Car::moveBy(int dx, int dy) {
    moveTo(x + dx, y + dy);
}

#endif
