#include "NameRepository.h"

Iterator * NameRepository::getIterator()
{
	return new NameRepository::NameIterator(this);
}

bool NameRepository::NameIterator::hasNext()
{
	if (index < nameRepo->names.size())
		return true;
	else
		return false;
}

void * NameRepository::NameIterator::next()
{
	if (hasNext())
	{
		return &(nameRepo->names[index++]);
	}
	else
		return nullptr;
}
