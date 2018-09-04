#include "AbstractFactory.h"
#include "FactoryProducer.h"
#include "Shape.h"
#include "Color.h"

int main(int argc, char **argv)
{
	//��ȡ��״����
	std::unique_ptr<AbstractFactory> &shapeFactory = FactoryProducer::getFactory("SHAPE");

	//��ȡ��״Ϊ Circle �Ķ���
	std::shared_ptr<Shape> shape1 = shapeFactory->getShape("CIRCLE");

	//���� Circle �� draw ����
	shape1->draw();

	//��ȡ��״Ϊ Rectangle �Ķ���
	std::shared_ptr<Shape> shape2 = shapeFactory->getShape("RECTANGLE");

	//���� Rectangle �� draw ����
	shape2->draw();

	//��ȡ��״Ϊ Square �Ķ���
	std::shared_ptr<Shape> shape3 = shapeFactory->getShape("SQUARE");

	//���� Square �� draw ����
	shape3->draw();

	//��ȡ��ɫ����
	std::unique_ptr<AbstractFactory> &colorFactory = FactoryProducer::getFactory("COLOR");

	//��ȡ��ɫΪ Red �Ķ���
	std::shared_ptr<Color> color1 = colorFactory->getColor("RED");

	//���� Red �� fill ����
	color1->fill();

	//��ȡ��ɫΪ Green �Ķ���
	std::shared_ptr<Color> color2 = colorFactory->getColor("GREEN");

	//���� Green �� fill ����
	color2->fill();

	//��ȡ��ɫΪ Blue �Ķ���
	std::shared_ptr<Color> color3 = colorFactory->getColor("BLUE");

	//���� Blue �� fill ����
	color3->fill();

	system("pause");

	return 0;
}