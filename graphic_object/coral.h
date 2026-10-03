#ifndef CORAL_H
#define CORAL_H

#include "shape.h"
#include "line.h"
#include "circle.h"

class Coral : public Shape {
    private:
        Line trunk;
        Line left_branch;
        Line right_branch;
        Circle left_tip;
        Circle right_tip;

    public:
        Coral(int x, int y, int size, int shape_color);

        void draw() override;
        void erase() override;
};

#endif