#include "Person.h"

Person::Person(const std::string & name, const std::string & gender, const std::string & maritalStatus) : name(name), gender(gender), maritalStatus(maritalStatus)
{
}

const std::string & Person::getName() const
{
	// TODO: �ڴ˴����� return ���
	return name;
}

const std::string & Person::getGender() const
{
	// TODO: �ڴ˴����� return ���
	return gender;
}

const std::string & Person::getMaritalStatus() const
{
	// TODO: �ڴ˴����� return ���
	return maritalStatus;
}
