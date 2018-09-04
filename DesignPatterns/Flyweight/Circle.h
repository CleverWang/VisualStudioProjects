#pragma once

#include "Shape.h"
#include <string>

class Circle : public Shape
{
public:
	Circle(const std::string &color) : color(color) {}
	~Circle() = default;

	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setRadius(double radius) { this->radius = radius; }
	// Í¨¹ý Shape ¼Ì³Ð
	virtual void draw() override;

private:
	const std::string color;
	double x, y, radius;
};