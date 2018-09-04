#include "Shape.h"
#include "ShapeFactory.h"

int main(int argc, char **argv)
{
	ShapeFactory shapeFactory;

	//获取 Circle 的对象，并调用它的 draw 方法
	std::shared_ptr<Shape> shape1 = shapeFactory.getShape("CIRCLE");

	//调用 Circle 的 draw 方法
	shape1->draw();

	//获取 Rectangle 的对象，并调用它的 draw 方法
	std::shared_ptr<Shape> shape2 = shapeFactory.getShape("RECTANGLE");

	//调用 Rectangle 的 draw 方法
	shape2->draw();

	//获取 Square 的对象，并调用它的 draw 方法
	std::shared_ptr<Shape> shape3 = shapeFactory.getShape("SQUARE");

	//调用 Square 的 draw 方法
	shape3->draw();

	system("pause");

	return 0;
}