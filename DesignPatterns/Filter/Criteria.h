#pragma once

#include <vector>
#include "Person.h"

struct Criteria
{
	virtual std::vector<Person*> meetCriteria(std::vector<Person*> &persons) = 0;
	virtual ~Criteria() = default;
};