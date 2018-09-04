#pragma once

#include "Criteria.h"

class CriteriaSingle : public Criteria
{
public:
	CriteriaSingle() = default;
	~CriteriaSingle() = default;

	// ͨ�� Criteria �̳�
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;
};