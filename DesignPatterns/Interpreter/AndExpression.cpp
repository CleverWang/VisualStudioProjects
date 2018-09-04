#include "AndExpression.h"

bool AndExpression::interpret(const std::string & context)
{
	return expr1->interpret(context) && expr2->interpret(context);
}
