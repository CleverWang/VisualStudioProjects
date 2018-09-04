#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle() { type = "Rectangle"; }

	// Í¨¹ý Shape ¼Ì³Ð
	virtual void draw();

	virtual std::shared_ptr<Shape> clone() { return std::make_shared<Rectangle>(*this); }
};