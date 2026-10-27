#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape {
    private:
        int side;

    public:
        Square(int x, int y, int side, int shape_color, bool fill = true);

        void draw() override;
        void erase() override;
};

#endif