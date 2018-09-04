#pragma once

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

class ShapeMaker
{
public:
	ShapeMaker() : circle(new Circle), rectangle(new Rectangle), square(new Square) {}
	~ShapeMaker() { delete circle; delete rectangle; delete square; }

	void drawCircle();
	void drawRectangle();
	void drawSquare();

private:
	Shape * circle;
	Shape * rectangle;
	Shape * square;
};