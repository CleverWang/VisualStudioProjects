#pragma once

#include "Criteria.h"

class OrCriteria : public Criteria
{
public:
	OrCriteria(Criteria * criteria, Criteria * otherCriteria);
	~OrCriteria() = default;

	// Í¨¹ý Criteria ¼Ì³Ð
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;

private:
	Criteria * criteria;
	Criteria * otherCriteria;
};