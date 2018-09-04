#pragma once

#include "Shape.h"

class Square : public Shape
{
public:
	Square() { type = "Square"; }

	// Í¨¹ý Shape ¼Ì³Ð
	virtual void draw();

	virtual std::shared_ptr<Shape> clone() { return std::make_shared<Square>(*this); }
};