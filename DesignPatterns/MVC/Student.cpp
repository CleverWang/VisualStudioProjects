#include "Student.h"

void Student::setRollNo(const std::string & rollNo)
{
	this->rollNo = rollNo;
}

std::string Student::getRollNo() const
{
	return this->rollNo;
}

void Student::setName(const std::string & name)
{
	this->name = name;
}

std::string Student::getName() const
{
	return this->name;
}
