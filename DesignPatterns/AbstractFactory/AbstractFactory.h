#pragma once

#include "Color.h"
#include "Shape.h"
#include <memory>
#include <string>

struct AbstractFactory
{
	virtual std::shared_ptr<Color> getColor(const std::string &color) = 0;
	virtual std::shared_ptr<Shape> getShape(const std::string &shape) = 0;
	virtual ~AbstractFactory() = default;
};