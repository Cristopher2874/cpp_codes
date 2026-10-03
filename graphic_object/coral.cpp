#ifndef CORAL_CPP
#define CORAL_CPP

#include "coral.h"

Coral::Coral(int x, int y, int size, int shape_color)
    : Shape(x, y, shape_color, false),
      trunk(x, y, x, y - size, shape_color),
      left_branch(x, y - size / 3, x - size / 2, y - 2 * size / 3, shape_color),
      right_branch(x, y - size / 2, x + size / 2, y - 3 * size / 4, shape_color),
      left_tip(x - size / 2, y - 2 * size / 3, size / 8, shape_color, true),
      right_tip(x + size / 2, y - 3 * size / 4, size / 8, shape_color, true) {}

void Coral::draw() {
    trunk.draw();
    left_branch.draw();
    right_branch.draw();
    left_tip.draw();
    right_tip.draw();
}

void Coral::erase() {
    trunk.erase();
    left_branch.erase();
    right_branch.erase();
    left_tip.erase();
    right_tip.erase();
}

#endif