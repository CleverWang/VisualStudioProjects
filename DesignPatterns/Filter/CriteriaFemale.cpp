#include "CriteriaFemale.h"

std::vector<Person*> CriteriaFemale::meetCriteria(std::vector<Person*>& persons)
{
	std::vector<Person*> femalePersons;
	for (auto &person : persons)
	{
		if (person->getGender() == "FEMALE")
		{
			femalePersons.push_back(person);
		}
	}
	return femalePersons;
}
