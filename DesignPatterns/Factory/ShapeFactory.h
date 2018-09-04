#pragma once

#include "Shape.h"
#include <string>
#include <memory>

struct ShapeFactory
{
	std::shared_ptr<Shape> getShape(const std::string &shapeType);
};