#include "triangle.h"
#include "miniwin.h"

#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP

Triangle::Triangle(int x, int y, int size, int shape_color,
                   int direction, bool fill)
    : Shape(x, y, shape_color, fill) {
    this->size = size;
    this->direction = direction % 4;
    if (this->direction < 0)
        this->direction += 4;
}

void Triangle::draw() {
    miniwin::color(shape_color);

    if (!fill) {
        int half_size = size / 2;

        if (direction == 0) {
            miniwin::linea(x + half_size, y, x - half_size, y - half_size);
            miniwin::linea(x - half_size, y - half_size, x - half_size, y + half_size);
            miniwin::linea(x - half_size, y + half_size, x + half_size, y);
        } else if (direction == 1) {
            miniwin::linea(x, y + half_size, x - half_size, y - half_size);
            miniwin::linea(x - half_size, y - half_size, x + half_size, y - half_size);
            miniwin::linea(x + half_size, y - half_size, x, y + half_size);
        } else if (direction == 2) {
            miniwin::linea(x - half_size, y, x + half_size, y - half_size);
            miniwin::linea(x + half_size, y - half_size, x + half_size, y + half_size);
            miniwin::linea(x + half_size, y + half_size, x - half_size, y);
        } else {
            miniwin::linea(x, y - half_size, x - half_size, y + half_size);
            miniwin::linea(x - half_size, y + half_size, x + half_size, y + half_size);
            miniwin::linea(x + half_size, y + half_size, x, y - half_size);
        }
        return;
    }

    int half_size = size / 2;
    for (int offset = -half_size; offset <= half_size; offset++) {
        int distance_from_center = offset < 0 ? -offset : offset;

        if (direction == 0) {
            miniwin::linea(x - half_size, y + offset,
                           x + half_size - 2 * distance_from_center, y + offset);
        } else if (direction == 1) {
            miniwin::linea(x + offset, y - half_size,
                           x + offset, y + half_size - 2 * distance_from_center);
        } else if (direction == 2) {
            miniwin::linea(x - half_size + 2 * distance_from_center, y + offset,
                           x + half_size, y + offset);
        } else {
            miniwin::linea(x + offset, y - half_size + 2 * distance_from_center,
                           x + offset, y + half_size);
        }
    }
}

void Triangle::erase() {
    int previous_color = shape_color;
    shape_color = miniwin::NEGRO;
    draw();
    shape_color = previous_color;
}

#endif