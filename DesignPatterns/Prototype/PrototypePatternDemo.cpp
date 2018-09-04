#include "Shape.h"
#include "ShapeCache.h"
#include <iostream>

int main(int argc, char** argv)
{
	ShapeCache::loadCache();

	std::shared_ptr<Shape> clonedShape = ShapeCache::getShape("1");
	std::cout << "Shape : " + clonedShape->getType() << std::endl;

	clonedShape = ShapeCache::getShape("2");
	std::cout << "Shape : " + clonedShape->getType() << std::endl;

	clonedShape = ShapeCache::getShape("3");
	std::cout << "Shape : " + clonedShape->getType() << std::endl;

	system("pause");

	return 0;
}