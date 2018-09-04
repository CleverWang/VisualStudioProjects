#include "ShapeFactory.h"
#include "Circle.h"
#include <random>

std::string colors[5] = { "Red", "Green", "Blue", "White", "Black" };
std::default_random_engine e;
std::string getRandomColor()
{
	static std::uniform_int_distribution<unsigned> uid(0, 4);
	return colors[uid(e)];
}
double getRandomX()
{
	static std::uniform_real_distribution<double> urdx(0, 99);
	return urdx(e);
}
double getRandomY()
{
	static std::uniform_real_distribution<double> urdy(0, 99);
	return urdy(e);
}

int main(int argc, char **argv)
{
	for (int i = 0; i < 20; ++i)
	{
		Circle *circle = static_cast<Circle*>(ShapeFactory::getCircle(getRandomColor()));
		circle->setX(getRandomX());
		circle->setY(getRandomY());
		circle->setRadius(100);
		circle->draw();
	}
	return 0;
}