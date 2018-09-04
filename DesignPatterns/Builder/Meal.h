#pragma once

#include "Item.h"
#include <vector>
#include <iostream>

class Meal
{
public:
	Meal();
	~Meal();

	void addItem(std::shared_ptr<Item> item);
	float getCost();
	void showItems();

private:
	std::vector<std::shared_ptr<Item>> items;
};

Meal::Meal()
{
}

Meal::~Meal()
{
}

inline void Meal::addItem(std::shared_ptr<Item> item)
{
	items.push_back(item);
}

inline float Meal::getCost()
{
	float cost = 0.0f;
	for (auto item : items)
	{
		cost += item->price();
	}
	return cost;
}

inline void Meal::showItems()
{
	for (auto item : items)
	{
		std::cout << "Item : " << item->name();
		std::cout << ", Packing : " << item->packing()->pack();
		std::cout << ", Price : " << item->price() << std::endl;
	}
}
