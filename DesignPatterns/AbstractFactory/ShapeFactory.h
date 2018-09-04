#pragma once

#include "AbstractFactory.h"

struct ShapeFactory : public AbstractFactory
{
	// ͨ�� AbstractFactory �̳�
	virtual std::shared_ptr<Color> getColor(const std::string & color) override;
	virtual std::shared_ptr<Shape> getShape(const std::string & shape) override;
};