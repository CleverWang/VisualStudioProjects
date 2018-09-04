#pragma once

#include "Expression.h"

class AndExpression : public Expression
{
public:
	AndExpression(Expression *expr1, Expression *expr2) : expr1(expr1), expr2(expr2) {}
	~AndExpression() { delete expr1; delete expr2; }

	// ͨ�� Expression �̳�
	virtual bool interpret(const std::string & context) override;

private:
	Expression * expr1;
	Expression * expr2;
};