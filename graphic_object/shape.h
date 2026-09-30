#ifndef SHAPE_H
#define SHAPE_H
#include "miniwin.h"

class Shape {
    protected:
        int x;
        int y;
        int shape_color;
        bool fill;

    public:
        Shape(int x, int y, int shape_color, bool fill = true);

        virtual ~Shape();
        virtual void draw() = 0;
        virtual void erase() = 0;
};

#endif