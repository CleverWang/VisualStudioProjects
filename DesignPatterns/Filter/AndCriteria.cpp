#include "AndCriteria.h"

AndCriteria::AndCriteria(Criteria* criteria, Criteria* otherCriteria) : criteria(criteria), otherCriteria(otherCriteria)
{
}

std::vector<Person*> AndCriteria::meetCriteria(std::vector<Person*>& persons)
{
	std::vector<Person*> firstCriteriaPersons = criteria->meetCriteria(persons);
	return otherCriteria->meetCriteria(firstCriteriaPersons);
}
