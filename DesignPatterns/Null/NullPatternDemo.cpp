#include "AbstractCustomer.h"
#include "CustomerFactory.h"
#include <iostream>

int main(int argc, char **argv)
{
	AbstractCustomer *customer1 = CustomerFactory::getCustomer("Rob");
	AbstractCustomer *customer2 = CustomerFactory::getCustomer("Bob");
	AbstractCustomer *customer3 = CustomerFactory::getCustomer("Julie");
	AbstractCustomer *customer4 = CustomerFactory::getCustomer("Laura");

	std::cout << "Customers" << std::endl;
	std::cout << customer1->getName() << std::endl;
	std::cout << customer2->getName() << std::endl;
	std::cout << customer3->getName() << std::endl;
	std::cout << customer4->getName() << std::endl;

	delete customer1;
	delete customer2;
	delete customer3;
	delete customer4;

	return 0;
}