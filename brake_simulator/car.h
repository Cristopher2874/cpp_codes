#ifndef CAR_H
#define CAR_H

#include "wheel.h"

class Car {
private:
    Wheel front_left_wheel;
    Wheel front_right_wheel;
    Wheel rear_left_wheel;
    Wheel rear_right_wheel;

public:
    Car(int x = 320, int y = 240, int wheel_width = 30, int wheel_side = 30);

    void draw();
    void erase();
};

#endif
