#include "Employee.h"

int main(int argc, char **argv)
{
	Employee CEO("John", "CEO", 30000);

	Employee headSales("Robert", "Head Sales", 20000);
	Employee headMarketing("Michel", "Head Marketing", 20000);

	Employee salesExecutive1("Richard", "Sales", 10000);
	Employee salesExecutive2("Rob", "Sales", 10000);

	Employee clerk1("Laura", "Marketing", 10000);
	Employee clerk2("Bob", "Marketing", 10000);

	CEO.add(&headSales);
	CEO.add(&headMarketing);

	headSales.add(&salesExecutive1);
	headSales.add(&salesExecutive2);

	headMarketing.add(&clerk1);
	headMarketing.add(&clerk2);

	//打印该组织的所有员工
	std::cout << CEO << std::endl;
	for (Employee *headEmployee : CEO.getSubordinates()) {
		std::cout << *headEmployee << std::endl;
		for (Employee *employee : headEmployee->getSubordinates()) {
			std::cout << *employee << std::endl;
		}
	}

	return 0;
}