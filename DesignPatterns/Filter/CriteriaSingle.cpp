#include "CriteriaSingle.h"

std::vector<Person*> CriteriaSingle::meetCriteria(std::vector<Person*>& persons)
{
	std::vector<Person*> singlePersons;
	for (auto &person : persons)
	{
		if (person->getMaritalStatus() == "SINGLE")
		{
			singlePersons.push_back(person);
		}
	}
	return singlePersons;
}
