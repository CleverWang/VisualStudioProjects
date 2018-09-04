#include "OrCriteria.h"
#include <algorithm>
#include <iterator>

OrCriteria::OrCriteria(Criteria * criteria, Criteria * otherCriteria) : criteria(criteria), otherCriteria(otherCriteria)
{
}

std::vector<Person*> OrCriteria::meetCriteria(std::vector<Person*>& persons)
{
	std::vector<Person *> firstCriteriaItems = criteria->meetCriteria(persons);
	std::vector<Person *> otherCrieriaItems = otherCriteria->meetCriteria(persons);
	std::vector<Person *> orResult;

	std::set_union(firstCriteriaItems.begin(), firstCriteriaItems.end(), otherCrieriaItems.begin(), otherCrieriaItems.end(), std::back_inserter(orResult));

	return orResult;
}
