#pragma once

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle() { type = "Circle"; }

	// Í¨¹ý Shape ¼Ì³Ð
	virtual void draw();

	virtual std::shared_ptr<Shape> clone() { return std::make_shared<Circle>(*this); }
};