#ifndef FRONT_WING_H
#define FRONT_WING_H

#include "shape.h"
#include "square.h"

class FrontWing : public Shape {
    private:
        Square left;
        Square right;

    public:
        FrontWing(int x, int y);

        void draw() override;
        void erase() override;
        void moveTo(int nx, int ny) override;
};

#endif
