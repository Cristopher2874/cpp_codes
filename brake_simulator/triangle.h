#include "shape.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape {
    private:
        int size;
        int direction;

    public:
        Triangle(int x, int y, int size, int shape_color,
                  int direction = 0, bool fill = true);

        void draw() override;
        void erase() override;
};

#endif