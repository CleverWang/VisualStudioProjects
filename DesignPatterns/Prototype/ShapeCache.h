#pragma once

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include <unordered_map>
#include <iostream>

class ShapeCache
{
public:
	ShapeCache();
	~ShapeCache();

	static std::shared_ptr<Shape> getShape(const std::string &shapeId) {
		std::shared_ptr<Shape> cachedShape = shapeMap[shapeId];
		return cachedShape->clone();
	}

	static void loadCache();

private:
	static std::unordered_map<std::string, std::shared_ptr<Shape>> shapeMap;
};

std::unordered_map<std::string, std::shared_ptr<Shape>> ShapeCache::shapeMap;

ShapeCache::ShapeCache()
{
}

ShapeCache::~ShapeCache()
{
}

inline void ShapeCache::loadCache()
{
	std::shared_ptr<Circle> circle = std::make_shared<Circle>();
	circle->setId("1");
	shapeMap.insert({ circle->getId(), circle });

	std::shared_ptr<Square> square = std::make_shared<Square>();
	square->setId("2");
	shapeMap.insert({ square->getId(), square });

	std::shared_ptr<Rectangle> rect = std::make_shared<Rectangle>();
	rect->setId("3");
	shapeMap.insert({ rect->getId(), rect });

	/*for (const auto &shape : shapeMap)
	{
		std::cout << "ID: " << shape.first << " Type: " << shape.second->getType() << std::endl;
	}*/
}
