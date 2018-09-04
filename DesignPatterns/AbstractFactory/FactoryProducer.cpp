#include "FactoryProducer.h"
#include <iostream>

 std::unique_ptr<AbstractFactory> FactoryProducer::shapeFactory(new ShapeFactory);
 std::unique_ptr<AbstractFactory> FactoryProducer::colorFactory(new ColorFactory);
 std::unique_ptr<AbstractFactory> FactoryProducer::nullFactory;

std::unique_ptr<AbstractFactory> &FactoryProducer::getFactory(const std::string & choice)
{
	if (choice.size() == 0)
	{
		return nullFactory;
	}
	if (choice == "SHAPE")
	{
		return shapeFactory;
	}
	else if (choice == "COLOR")
	{
		return colorFactory;
	}
	return nullFactory;
}
