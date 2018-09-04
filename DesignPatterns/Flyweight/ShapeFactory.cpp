#include "ShapeFactory.h"
#include <iostream>

std::unordered_map<std::string, Shape*> ShapeFactory::circleMap;

Shape * ShapeFactory::getCircle(const std::string & color)
{
	auto iter = circleMap.find(color);
	if (iter == circleMap.end())
	{
		Circle *circle = new Circle(color);
		circleMap.insert({ color, circle });
		std::cout << "Creating circle of color : " + color << std::endl;
		return circle;
	}
	else
	{
		return iter->second;
	}
}
