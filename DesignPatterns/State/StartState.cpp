#include "StartState.h"
#include "Context.h"
#include <iostream>

void StartState::doAction(Context * context)
{
	std::cout << "Player is in start state\n";
	context->setState(this);
}

std::string StartState::toString() const
{
	return "Start State";
}
