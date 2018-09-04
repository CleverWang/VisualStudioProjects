#include "CriteriaMale.h"

std::vector<Person*> CriteriaMale::meetCriteria(std::vector<Person*>& persons)
{
	std::vector<Person*> malePersons;
	for (auto &person : persons)
	{
		if (person->getGender() == "MALE")
		{
			malePersons.push_back(person);
		}
	}
	return malePersons;
}
