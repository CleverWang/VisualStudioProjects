#include "Circle.h"
#include <iostream>

void Circle::draw()
{
	std::cout << "Circle: Draw() [Color : " << color
		<< ", x : " << x << ", y :" << y << ", radius :" << radius << std::endl;
}
