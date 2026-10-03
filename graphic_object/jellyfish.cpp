#ifndef JELLYFISH_CPP
#define JELLYFISH_CPP

#include "jellyfish.h"
#include "miniwin.h"

Jellyfish::Jellyfish(int x, int y, int size, int shape_color)
    : Shape(x, y, shape_color, true),
      body(x, y - size / 4, size, shape_color, true),
      skirt(x, y + size / 2, 2 * size, shape_color, 1, true),
      eye_left(x - size / 3, y - size / 4, size / 8, miniwin::NEGRO, true),
      eye_right(x + size / 3, y - size / 4, size / 8, miniwin::NEGRO, true),
      tentacle_left_top(x - size / 2, y + size / 2,
                        x - 3 * size / 4, y + 3 * size / 4, shape_color),
      tentacle_left_bottom(x - 3 * size / 4, y + 3 * size / 4,
                           x - size / 2, y + 5 * size / 4, shape_color),
      tentacle_center_top(x, y + size / 2,
                          x - size / 8, y + size, shape_color),
      tentacle_center_bottom(x - size / 8, y + size,
                             x + size / 8, y + 5 * size / 4, shape_color),
      tentacle_right_top(x + size / 2, y + size / 2,
                         x + 3 * size / 4, y + 3 * size / 4, shape_color),
      tentacle_right_bottom(x + 3 * size / 4, y + 3 * size / 4,
                            x + size / 2, y + 5 * size / 4, shape_color) {}

void Jellyfish::draw() {
    body.draw();
    skirt.draw();
    eye_left.draw();
    eye_right.draw();
    tentacle_left_top.draw();
    tentacle_left_bottom.draw();
    tentacle_center_top.draw();
    tentacle_center_bottom.draw();
    tentacle_right_top.draw();
    tentacle_right_bottom.draw();
}

void Jellyfish::erase() {
    body.erase();
    skirt.erase();
    eye_left.erase();
    eye_right.erase();
    tentacle_left_top.erase();
    tentacle_left_bottom.erase();
    tentacle_center_top.erase();
    tentacle_center_bottom.erase();
    tentacle_right_top.erase();
    tentacle_right_bottom.erase();
}

#endif