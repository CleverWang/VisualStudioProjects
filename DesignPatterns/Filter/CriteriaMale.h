#pragma once

#include "Criteria.h"

class CriteriaMale : public Criteria
{
public:
	CriteriaMale() = default;
	~CriteriaMale() = default;

	// Í¨¹ý Criteria ¼Ì³Ð
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;
};