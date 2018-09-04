#include "Shape.h"
#include "Circle.h"
#include "RedCircle.h"
#include "GreenCircle.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	Shape *redCircle = new Circle(100, 100, 10, new RedCircle);
	Shape *greenCircle = new Circle(100, 100, 10, new GreenCircle);

	redCircle->draw();
	greenCircle->draw();

	delete redCircle;
	delete greenCircle;

	system("pause");

	return 0;
}