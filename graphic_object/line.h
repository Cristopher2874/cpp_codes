#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape {
    private:
        int x2;
        int y2;

    public:
        Line(int x1, int y1, int x2, int y2, int shape_color);

        void draw() override;
        void erase() override;
};

#endif