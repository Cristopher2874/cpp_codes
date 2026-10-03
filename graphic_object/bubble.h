#ifndef BUBBLE_H
#define BUBBLE_H

#include "shape.h"
#include "circle.h"

class Bubble : public Shape {
    private:
        int radius;
        Circle outline;
        Circle highlight;

    public:
        Bubble(int x, int y, int radius);

        void draw() override;
        void erase() override;
};

#endif