#ifndef BUBBLE_CPP
#define BUBBLE_CPP

#include "bubble.h"
#include "miniwin.h"

Bubble::Bubble(int x, int y, int radius)
    : Shape(x, y, miniwin::CYAN, false),
      radius(radius),
      outline(x, y, radius, miniwin::CYAN, false),
      highlight(x - radius / 3, y - radius / 3, radius / 6, miniwin::BLANCO, true) {}

void Bubble::draw() {
    outline.draw();
    highlight.draw();
}

void Bubble::erase() {
    outline.erase();
    highlight.erase();
}

#endif