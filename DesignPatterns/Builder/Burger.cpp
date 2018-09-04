#include "Burger.h"
#include "Wrapper.h"

std::shared_ptr<Packing> Burger::packing()
{
	return std::make_shared<Wrapper>();
}
