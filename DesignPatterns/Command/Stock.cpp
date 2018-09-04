#include "Stock.h"
#include <iostream>

void Stock::buy()
{
	std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity <<" ] bought "<< std::endl;
}

void Stock::sell()
{
	std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold" << std::endl;
}
