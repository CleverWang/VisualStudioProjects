#include "ColdDrink.h"
#include "Bottle.h"

std::shared_ptr<Packing> ColdDrink::packing()
{
	return std::make_shared<Bottle>();
}

