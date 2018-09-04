#pragma once

#include "Shape.h"
#include "Circle.h"
#include <unordered_map>
#include <string>

class ShapeFactory
{
public:
	static Shape *getCircle(const std::string &color);

private:
	static std::unordered_map<std::string, Shape*> circleMap;
};