#pragma once

#include <vector>
#include <string>
#include <iostream>

class Employee
{
	friend std::ostream &operator<<(std::ostream &os, const Employee &e);
public:
	Employee(const std::string &name, const std::string &dept, int salary);
	~Employee() = default;

	void add(Employee *e);
	void remove(Employee *e);
	std::vector<Employee*> getSubordinates();

private:
	std::string name;
	std::string dept;
	int salary;
	std::vector<Employee*> subordinates;
};