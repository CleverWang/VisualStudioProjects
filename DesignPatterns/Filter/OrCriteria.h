#pragma once

#include "Criteria.h"

class OrCriteria : public Criteria
{
public:
	OrCriteria(Criteria * criteria, Criteria * otherCriteria);
	~OrCriteria() = default;

	// ͨ�� Criteria �̳�
	virtual std::vector<Person*> meetCriteria(std::vector<Person*>& persons) override;

private:
	Criteria * criteria;
	Criteria * otherCriteria;
};