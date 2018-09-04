#pragma once

#include "ShapeDecorator.h"
#include "Shape.h"

class RedShapeDecorator : public ShapeDecorator
{
public:
	RedShapeDecorator(Shape *decoratedShape) : ShapeDecorator(decoratedShape) {}
	~RedShapeDecorator() = default;

	void draw();

private:
	void setRedBorder(Shape *decoratedShape);
};