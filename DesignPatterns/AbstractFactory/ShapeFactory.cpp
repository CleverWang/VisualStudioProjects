#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include <iostream>

std::shared_ptr<Color> ShapeFactory::getColor(const std::string & color)
{
	return nullptr;
}

std::shared_ptr<Shape> ShapeFactory::getShape(const std::string & shape)
{
	
	if (shape.size() == 0)
	{
		std::cout << "Please input a shape type!\n";
		return nullptr;
	}
	if (shape == "CIRCLE")
	{
		return std::make_shared<Circle>();
	}
	else if (shape == "RECTANGLE")
	{
		return std::make_shared<Rectangle>();
	}
	else if (shape == "SQUARE")
	{
		return std::make_shared<Square>();
	}
	std::cout << "No such a shape type!\n";
	return nullptr;
}
