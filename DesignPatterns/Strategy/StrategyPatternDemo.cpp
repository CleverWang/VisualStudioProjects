#include "Context.h"
#include "OperationAdd.h"
#include "OperationMultiply.h"
#include "OperationSubstract.h"
#include <iostream>

int main(int argc, char **argv)
{
	Context *context = new Context(new OperationAdd());
	std::cout << "10 + 5 = " << context->executeStrategy(10, 5) << std::endl;
	delete context;

	context = new Context(new OperationSubstract());
	std::cout << "10 - 5 = " << context->executeStrategy(10, 5) << std::endl;
	delete context;

	context = new Context(new OperationMultiply());
	std::cout << "10 * 5 = " << context->executeStrategy(10, 5) << std::endl;
	delete context;

	return 0;
}