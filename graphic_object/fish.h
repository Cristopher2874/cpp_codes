#ifndef FISH_H
#define FISH_H

#include "shape.h"
#include "circle.h"
#include "triangle.h"

class Fish : public Shape {
	private:
		int size;
		Circle body;
		Circle eye;
		Triangle tail;

	public:
		Fish(int x, int y, int size, int shape_color);

		void draw() override;
		void erase() override;
};

#endif
