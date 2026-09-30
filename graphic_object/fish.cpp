#ifndef FISH_CPP
#define FISH_CPP

#include "fish.h"
#include "miniwin.h"

Fish::Fish(int x, int y, int size, int shape_color)
	: Shape(x, y, shape_color, true),
	  size(size),
	  body(x, y, size, shape_color),
	  eye(x + size / 3, y - size / 3, size / 8, miniwin::NEGRO) {
}

void Fish::draw_tail(int color) {
	miniwin::color(color);

	// Invierte el triangulo: el vertice queda junto al cuerpo.
	for (int offset = -size; offset <= size; offset++) {
		int right = x - size - (offset < 0 ? -offset : offset);
		miniwin::linea(x - 2 * size, y + offset, right, y + offset);
	}

	miniwin::linea(x - 2 * size, y - size, x - size, y);
	miniwin::linea(x - 2 * size, y + size, x - size, y);
}

void Fish::draw() {
	draw_tail(shape_color);
	body.draw();
	eye.draw();
}

void Fish::erase() {
	draw_tail(miniwin::NEGRO);
	body.erase();
	eye.erase();
}

#endif
