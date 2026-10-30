#ifndef CHASSIS_H
#define CHASSIS_H

#include "shape.h"
#include "square.h"

class Chassis : public Shape {
    private:
        int side;
        Square body;

    public:
        Chassis(int x, int y, int side = 80);

        void draw() override;
        void erase() override;
        void moveTo(int nx, int ny) override;
};

#endif
