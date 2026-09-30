#ifndef FISH_CPP
#define FISH_CPP

#include "fish.h"
#include "miniwin.h"

Fish::Fish(int x, int y, int size, int shape_color)
	: Shape(x, y, shape_color, true),
	  body(x, y, size, shape_color, true),
	  eye(x + size / 3, y - size / 3, size / 8, miniwin::NEGRO),
	  tail(x - 3 * size / 2, y, 2 * size, shape_color, 0) {
    this->size = size;
}

void Fish::draw() {
	tail.draw();
	body.draw();
	eye.draw();
}

void Fish::erase() {
	tail.erase();
	body.erase();
	eye.erase();
}

#endif
