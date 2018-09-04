#pragma once

#include <string>

class AbstractCustomer
{
public:
	AbstractCustomer() = default;
	AbstractCustomer(const std::string &name) : name(name) {}
	virtual ~AbstractCustomer() = default;

	virtual bool isNil() const = 0;
	virtual std::string getName() const = 0;
	
protected:
	std::string name;
};