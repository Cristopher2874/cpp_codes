#include "car.h"

Car::Car(int x, int y, int wheel_width, int wheel_side)
    : front_left_wheel(wheel_width, x - 60, y - 45, wheel_side),
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
