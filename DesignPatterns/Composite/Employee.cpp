#include "Employee.h"

Employee::Employee(const std::string &name, const std::string &dept, int salary) : name(name), dept(dept), salary(salary)
{
}

void Employee::add(Employee * e)
{
	subordinates.push_back(e);
}

void Employee::remove(Employee * e)
{
	auto iter = std::find(subordinates.begin(), subordinates.end(), e);
	if (iter != subordinates.end())
		subordinates.erase(iter);
}

std::vector<Employee*> Employee::getSubordinates()
{
	return subordinates;
}

std::ostream & operator<<(std::ostream & os, const Employee & e)
{
	os << "Employee :[ Name : " << e.name
		<< ", dept : " << e.dept << ", salary :"
		<< e.salary << " ]";
	return os;
}
