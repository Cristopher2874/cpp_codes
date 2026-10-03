#ifndef JELLYFISH_H
#define JELLYFISH_H

#include "shape.h"
#include "circle.h"
#include "line.h"
#include "triangle.h"

class Jellyfish : public Shape {
    private:
        Circle body;
        Triangle skirt;
        Circle eye_left;
        Circle eye_right;
        Line tentacle_left_top;
        Line tentacle_left_bottom;
        Line tentacle_center_top;
        Line tentacle_center_bottom;
        Line tentacle_right_top;
        Line tentacle_right_bottom;

    public:
        Jellyfish(int x, int y, int size, int shape_color);

        void draw() override;
        void erase() override;
};

#endif