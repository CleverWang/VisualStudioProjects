#pragma once

#include "Expression.h"

class OrExpression : public Expression
{
public:
	OrExpression(Expression *expr1, Expression *expr2) : expr1(expr1), expr2(expr2) {}
	~OrExpression() { delete expr1; delete expr2; }

	// Í¨¹ý Expression ¼Ì³Ð
	virtual bool interpret(const std::string & context) override;

private:
	Expression * expr1;
	Expression * expr2;
};