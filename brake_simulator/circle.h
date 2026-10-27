#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape {
    private:
        int radius;

    public:
        Circle(int x, int y, int radius, int shape_color, bool fill = true);

        void draw() override;
        void erase() override;
};

#endif