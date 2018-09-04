#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>

std::shared_ptr<Shape> ShapeFactory::getShape(const std::string & shapeType)
{
	if (shapeType.size() == 0)
	{
		std::cout << "Please input a shape type!\n";
		return nullptr;
	}
	if (shapeType == "CIRCLE")
	{
		return std::make_shared<Circle>();
	}
	else if (shapeType == "RECTANGLE")
	{
		return std::make_shared<Rectangle>();
	}
	else if (shapeType == "SQUARE")
	{
		return std::make_shared<Square>();
	}
	std::cout << "No such a shape type!\n";
	return nullptr;
}
