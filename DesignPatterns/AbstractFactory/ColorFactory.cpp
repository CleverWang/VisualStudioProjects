#include "ColorFactory.h"
#include "Red.h"
#include "Green.h"
#include "Blue.h"
#include <iostream>

std::shared_ptr<Color> ColorFactory::getColor(const std::string & color)
{
	if (color.size() == 0)
	{
		std::cout << "Please input a color type!\n";
		return nullptr;
	}
	if (color == "RED")
	{
		return std::make_shared<Red>();
	}
	else if (color == "GREEN")
	{
		return std::make_shared<Green>();
	}
	else if (color == "BLUE")
	{
		return std::make_shared<Blue>();
	}
	std::cout << "No such a color type!\n";
	return nullptr;
}

std::shared_ptr<Shape> ColorFactory::getShape(const std::string & shape)
{
	return nullptr;
}
