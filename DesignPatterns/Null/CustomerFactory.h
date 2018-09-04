#pragma once

#include "AbstractCustomer.h"
#include <vector>

struct CustomerFactory
{
	static std::vector<std::string> names;
	static AbstractCustomer *getCustomer(const std::string &name);
};