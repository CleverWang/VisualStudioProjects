#pragma once

#include "Criteria.h"

class CriteriaFemale : public Criteria
{
public:
	CriteriaFemale() = default;
	~CriteriaFemale() = default;

	// ͨ�� Criteria �̳�
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;
};
