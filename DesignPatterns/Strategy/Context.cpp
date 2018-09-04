#include "Context.h"

int Context::executeStrategy(int num1, int num2)
{
	return strategy->doOperation(num1, num2);
}
