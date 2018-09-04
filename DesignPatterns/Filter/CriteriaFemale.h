#pragma once

#include "Criteria.h"

class CriteriaFemale : public Criteria
{
public:
	CriteriaFemale() = default;
	~CriteriaFemale() = default;

	// Í¨¹ý Criteria ¼Ì³Ð
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;
};
