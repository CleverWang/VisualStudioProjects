#include "Expression.h"
#include "AndExpression.h"
#include "OrExpression.h"
#include "TerminalExpression.h"
#include <iostream>

Expression *getMaleExpression()
{
	Expression *robert = new TerminalExpression("Robert");
	Expression *john = new TerminalExpression("John");
	return new OrExpression(robert, john);
}

Expression *getMarriedWomanExpression()
{
	Expression *julia = new TerminalExpression("Julia");
	Expression *married = new TerminalExpression("Married");
	return new AndExpression(julia, married);
}

int main(int argc, char **argv)
{
	Expression *isMale = getMaleExpression();
	Expression *isMarriedWoman = getMarriedWomanExpression();

	std::cout << "John is male? " << isMale->interpret("John") << std::endl;
	std::cout << "Julie is a married women? " << isMarriedWoman->interpret("Married Julia") << std::endl;

	delete isMale;
	delete isMarriedWoman;

	return 0;
}