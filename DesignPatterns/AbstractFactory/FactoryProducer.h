#pragma once

#include "AbstractFactory.h"
#include "ShapeFactory.h"
#include "ColorFactory.h"
#include <memory>

struct FactoryProducer
{
	static std::unique_ptr<AbstractFactory> &getFactory(const std::string &choice);
private:
	static std::unique_ptr<AbstractFactory> shapeFactory;
	static std::unique_ptr<AbstractFactory> colorFactory;
	static std::unique_ptr<AbstractFactory> nullFactory;
};