#pragma once

#include "Criteria.h"

class CriteriaSingle : public Criteria
{
public:
	CriteriaSingle() = default;
	~CriteriaSingle() = default;

	// Í¨¹ý Criteria ¼Ì³Ð
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;
};