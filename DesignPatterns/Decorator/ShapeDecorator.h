#pragma once

#include "Shape.h"

class ShapeDecorator : public Shape
{
public:
	ShapeDecorator(Shape *decoratedShape) : decoratedShape(decoratedShape) {}
	~ShapeDecorator() = default;

	// Í¨¹ý Shape ¼Ì³Ð
	virtual void draw() override;

protected:
	Shape * decoratedShape;
};