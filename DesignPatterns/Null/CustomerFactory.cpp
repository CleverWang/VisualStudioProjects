#include "CustomerFactory.h"
#include "RealCustomer.h"
#include "NullCustomer.h"

std::vector<std::string> CustomerFactory::names{ "Rob", "Joe", "Julie" };

AbstractCustomer * CustomerFactory::getCustomer(const std::string & name)
{
	for (auto &name_item : names)
	{
		if (name_item == name)
			return new RealCustomer(name);
	}
	return new NullCustomer();
}
