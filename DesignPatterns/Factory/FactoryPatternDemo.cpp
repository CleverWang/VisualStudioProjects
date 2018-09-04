#include "Shape.h"
#include "ShapeFactory.h"

int main(int argc, char **argv)
{
	ShapeFactory shapeFactory;

	//��ȡ Circle �Ķ��󣬲��������� draw ����
	std::shared_ptr<Shape> shape1 = shapeFactory.getShape("CIRCLE");

	//���� Circle �� draw ����
	shape1->draw();

	//��ȡ Rectangle �Ķ��󣬲��������� draw ����
	std::shared_ptr<Shape> shape2 = shapeFactory.getShape("RECTANGLE");

	//���� Rectangle �� draw ����
	shape2->draw();

	//��ȡ Square �Ķ��󣬲��������� draw ����
	std::shared_ptr<Shape> shape3 = shapeFactory.getShape("SQUARE");

	//���� Square �� draw ����
	shape3->draw();

	system("pause");

	return 0;
}