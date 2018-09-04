#include "Context.h"
#include "StartState.h"
#include "StopState.h"
#include <iostream>

int main(int argc, char **argv)
{
	Context *context = new Context();

	StartState *startState = new StartState();
	startState->doAction(context);

	std::cout << context->getState()->toString() << std::endl;

	StopState *stopState = new StopState();
	stopState->doAction(context);

	std::cout << context->getState()->toString() << std::endl;

	delete stopState;
	delete startState;
	delete context;

	return 0;
}