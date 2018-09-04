#include "Person.h"

Person::Person(const std::string & name, const std::string & gender, const std::string & maritalStatus) : name(name), gender(gender), maritalStatus(maritalStatus)
{
}

const std::string & Person::getName() const
{
	// TODO: 在此处插入 return 语句
	return name;
}

const std::string & Person::getGender() const
{
	// TODO: 在此处插入 return 语句
	return gender;
}

const std::string & Person::getMaritalStatus() const
{
	// TODO: 在此处插入 return 语句
	return maritalStatus;
}
