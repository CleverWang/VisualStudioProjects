#pragma once

#include <string>

class Student
{
public:
	Student() = default;
	~Student() = default;

	void setRollNo(const std::string &rollNo);
	std::string getRollNo() const;
	void setName(const std::string &name);
	std::string getName() const;

private:
	std::string rollNo;
	std::string name;
};