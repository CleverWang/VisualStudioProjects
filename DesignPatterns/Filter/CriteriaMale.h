#pragma once

#include "Criteria.h"

class CriteriaMale : public Criteria
{
public:
	CriteriaMale() = default;
	~CriteriaMale() = default;

	// ͨ�� Criteria �̳�
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;
};