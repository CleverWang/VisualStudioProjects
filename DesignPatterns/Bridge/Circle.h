#pragma once

#include "Shape.h"
#include "DrawAPI.h"

class Circle : public Shape
{
public:
	Circle(int x, int y, int r, DrawAPI *drawAPI) : Shape(drawAPI), x(x), y(y), r(r) {}
	~Circle() = default;

	// Í¨¹ý Shape ¼Ì³Ð
	virtual void draw() override;

private:
	int x, y, r;
};