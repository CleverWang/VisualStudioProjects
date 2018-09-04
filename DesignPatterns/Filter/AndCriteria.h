#pragma once

#include "Criteria.h"

class AndCriteria : public Criteria
{
public:
	AndCriteria(Criteria* criteria, Criteria* otherCriteria);
	~AndCriteria() = default;

	// Í¨¹ý Criteria ¼Ì³Ð
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;

private:
	Criteria * criteria;
	Criteria *otherCriteria;
};