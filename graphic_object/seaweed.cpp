#ifndef SEAWEED_CPP
#define SEAWEED_CPP

#include "seaweed.h"

Seaweed::Seaweed(int x, int y, int height, int shape_color)
    : Shape(x, y, shape_color, false),
      stem(x, y, x + height / 5, y - height, shape_color),
      back_stem(x - height / 5, y, x - height / 3, y - 3 * height / 4,
                shape_color),
      left_leaf(x + height / 5, y - height / 2,
                x - height / 4, y - 3 * height / 4, shape_color),
      right_leaf(x + height / 10, y - height / 3,
                 x + height / 2, y - height / 2, shape_color),
      back_left_leaf(x - height / 3, y - height / 3,
                     x - 2 * height / 3, y - height / 2, shape_color),
      back_right_leaf(x - height / 4, y - height / 2,
                      x + height / 10, y - 2 * height / 3, shape_color),
      top_tip(x + height / 5, y - height, height / 10, shape_color, true),
      left_tip(x - height / 4, y - 3 * height / 4,
               height / 10, shape_color, true),
      right_tip(x + height / 2, y - height / 2,
                height / 10, shape_color, true),
      back_left_tip(x - 2 * height / 3, y - height / 2,
                    height / 10, shape_color, true),
      back_right_tip(x + height / 10, y - 2 * height / 3,
                     height / 10, shape_color, true) {}

void Seaweed::draw() {
    stem.draw();
    back_stem.draw();
    left_leaf.draw();
    right_leaf.draw();
    back_left_leaf.draw();
    back_right_leaf.draw();
    top_tip.draw();
    left_tip.draw();
    right_tip.draw();
    back_left_tip.draw();
    back_right_tip.draw();
}

void Seaweed::erase() {
    stem.erase();
    back_stem.erase();
    left_leaf.erase();
    right_leaf.erase();
    back_left_leaf.erase();
    back_right_leaf.erase();
    top_tip.erase();
    left_tip.erase();
    right_tip.erase();
    back_left_tip.erase();
    back_right_tip.erase();
}

#endif