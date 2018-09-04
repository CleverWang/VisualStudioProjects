#include "Shape.h"
#include "RedShapeDecorator.h"
#include "Circle.h"
#include "Rectangle.h"

#include <iostream>

int main(int argc, char **argv)
{
	Shape *circle = new Circle();
	Shape *rectangle = new Rectangle();
	Shape *redCircle = new RedShapeDecorator(circle);
	Shape *redRectangle = new RedShapeDecorator(rectangle);

	std::cout << "Circle with normal border\n";
	circle->draw();

	std::cout << "\nRectangle with normal border\n";
	rectangle->draw();

	std::cout << "\nCircle of red border\n";
	redCircle->draw();

	std::cout << "\nRectangle of red border\n";
	redRectangle->draw();

	delete circle;
	delete rectangle;
	delete redCircle;
	delete redRectangle;

	return 0;
}