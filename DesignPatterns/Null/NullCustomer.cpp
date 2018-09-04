#include "NullCustomer.h"

bool NullCustomer::isNil() const
{
	return true;
}

std::string NullCustomer::getName() const
{
	return "Not Available in Customer Database";
}
