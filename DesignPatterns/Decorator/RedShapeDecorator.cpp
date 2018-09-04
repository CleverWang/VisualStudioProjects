#include "RedShapeDecorator.h"
#include <iostream>

void RedShapeDecorator::draw()
{
	decoratedShape->draw();
	setRedBorder(decoratedShape);
}

void RedShapeDecorator::setRedBorder(Shape * decoratedShape)
{
	std::cout << "Border Color: Red\n";
}
