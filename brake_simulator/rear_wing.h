#ifndef REAR_WING_H
#define REAR_WING_H

#include "shape.h"
#include "square.h"

class RearWing : public Shape {
    private:
        Square left;
        Square right;

    public:
        RearWing(int x, int y);

        void draw() override;
        void erase() override;
        void moveTo(int nx, int ny) override;
};

#endif
