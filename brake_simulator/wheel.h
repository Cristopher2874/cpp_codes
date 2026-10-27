#ifndef WHEEL_H
#define WHEEL_H

#include "shape.h"
#include "square.h"

class Wheel : public Shape {
    private:
        int width;
        Square current_wheel;

    public:
        Wheel(int width, int x, int y, int side);

        void draw() override;
        void erase() override;
};

#endif