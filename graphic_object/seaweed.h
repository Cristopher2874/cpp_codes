#ifndef SEAWEED_H
#define SEAWEED_H

#include "shape.h"
#include "line.h"
#include "circle.h"

class Seaweed : public Shape {
    private:
        Line stem;
        Line back_stem;
        Line left_leaf;
        Line right_leaf;
        Line back_left_leaf;
        Line back_right_leaf;
        Circle top_tip;
        Circle left_tip;
        Circle right_tip;
        Circle back_left_tip;
        Circle back_right_tip;

    public:
        Seaweed(int x, int y, int height, int shape_color);

        void draw() override;
        void erase() override;
};

#endif