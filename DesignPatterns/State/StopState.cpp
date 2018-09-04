#include "StopState.h"
#include "Context.h"
#include <iostream>

void StopState::doAction(Context * context)
{
	std::cout << "Player is in stop state\n";
	context->setState(this);
}

std::string StopState::toString() const
{
	return "Stop State";
}
