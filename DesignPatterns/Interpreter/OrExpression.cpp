#include "OrExpression.h"

bool OrExpression::interpret(const std::string & context)
{
	return expr1->interpret(context) || expr2->interpret(context);
}
