#pragma once

#include "Meal.h"
#include "VegBurger.h"
#include "ChickenBurger.h"
#include "Coke.h"
#include "Pepsi.h"

class MealBuilder
{
public:
	MealBuilder();
	~MealBuilder();

	std::shared_ptr<Meal> prepareVegMeal();
	std::shared_ptr<Meal> prepareNonVegMeal();

private:

};

MealBuilder::MealBuilder()
{
}

MealBuilder::~MealBuilder()
{
}

inline std::shared_ptr<Meal> MealBuilder::prepareVegMeal()
{
	std::shared_ptr<Meal> meal(new Meal);
	meal->addItem(std::make_shared<VegBurger>());
	meal->addItem(std::make_shared<Coke>());
	return meal;
}

inline std::shared_ptr<Meal> MealBuilder::prepareNonVegMeal()
{
	std::shared_ptr<Meal> meal(new Meal);
	meal->addItem(std::make_shared<ChickenBurger>());
	meal->addItem(std::make_shared<Pepsi>());
	return meal;
}
