#pragma once

#include <string>

class Person
{
public:
	Person(const std::string& name, const std::string& gender, const std::string& meritalStatus);
	~Person() = default;

	const std::string &getName() const;
	const std::string &getGender() const;
	const std::string &getMaritalStatus() const;

private:
	const std::string name;
	const std::string gender;
	const std::string maritalStatus;
};