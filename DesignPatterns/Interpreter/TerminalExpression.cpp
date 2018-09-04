#include "TerminalExpression.h"

bool TerminalExpression::interpret(const std::string & context)
{
	if (context.find(data) != std::string::npos)
		return true;
	else
		return false;
}
