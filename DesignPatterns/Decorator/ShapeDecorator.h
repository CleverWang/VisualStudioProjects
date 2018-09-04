#pragma once

#include "Shape.h"

class ShapeDecorator : public Shape
{
public:
	ShapeDecorator(Shape *decoratedShape) : decoratedShape(decoratedShape) {}
	~ShapeDecorator() = default;

	// ͨ�� Shape �̳�
	virtual void draw() override;

protected:
	Shape * decoratedShape;
};