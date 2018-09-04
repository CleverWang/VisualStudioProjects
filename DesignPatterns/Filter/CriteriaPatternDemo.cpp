#include "AndCriteria.h"
#include "Criteria.h"
#include "CriteriaFemale.h"
#include "CriteriaMale.h"
#include "CriteriaSingle.h"
#include "OrCriteria.h"
#include "Person.h"

#include <iostream>

void printPersons(std::vector<Person*> persons)
{
	for (auto &person : persons)
	{
		std::cout << "Person : [ Name : " + person->getName()
			+ ", Gender : " + person->getGender()
			+ ", Marital Status : " + person->getMaritalStatus()
			+ " ]\n";
	}
}

int main(int argc, char **argv)
{
	std::vector<Person *> persons;

	persons.push_back(new Person("Robert", "MALE", "SINGLE"));
	persons.push_back(new Person("John", "MALE", "MARRIED"));
	persons.push_back(new Person("Laura", "FEMALE", "MARRIED"));
	persons.push_back(new Person("Diana", "FEMALE", "SINGLE"));
	persons.push_back(new Person("Mike", "MALE", "SINGLE"));
	persons.push_back(new Person("Bobby", "MALE", "SINGLE"));

	Criteria *male = new CriteriaMale();
	Criteria *female = new CriteriaFemale();
	Criteria *single = new CriteriaSingle();
	Criteria *singleMale = new AndCriteria(single, male);
	Criteria *singleOrFemale = new OrCriteria(single, female);

	std::cout << "Males: \n";
	printPersons(male->meetCriteria(persons));

	std::cout << "Females: \n";
	printPersons(female->meetCriteria(persons));

	std::cout << "Single Males: \n";
	printPersons(singleMale->meetCriteria(persons));

	std::cout << "Single Or Females: \n";
	printPersons(singleOrFemale->meetCriteria(persons));

	delete male;
	delete female;
	delete single;
	delete singleMale;
	delete singleOrFemale;

	for (auto &person : persons)
	{
		delete person;
	}

	system("pause");

	return 0;
}