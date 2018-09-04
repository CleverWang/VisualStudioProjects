#include "MealBuilder.h"
#include "Meal.h"

int main(int argc, char** argv)
{
	MealBuilder mealBuilder;

	auto vegMeal = mealBuilder.prepareVegMeal();
	std::cout << "Veg Meal\n";
	vegMeal->showItems();
	std::cout << "Total Cost: " << vegMeal->getCost() << std::endl;

	auto nonVegMeal = mealBuilder.prepareNonVegMeal();
	std::cout << "\n\nNon-Veg Meal\n";
	nonVegMeal->showItems();
	std::cout << "Total Cost: " << nonVegMeal->getCost() << std::endl;

	system("pause");

	return 0;
}