#ifndef FISH_H
#define FISH_H

#include "shape.h"
#include "circle.h"

class Fish : public Shape {
	private:
		int size;
		Circle body;
		Circle eye;

		void draw_tail(int color);

	public:
		Fish(int x, int y, int size, int shape_color);

		void draw() override;
		void erase() override;
};

#endif
