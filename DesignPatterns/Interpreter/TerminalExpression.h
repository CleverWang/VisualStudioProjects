#pragma once

#include "Expression.h"

class TerminalExpression : public Expression
{
public:
	TerminalExpression(const std::string &data) : data(data) {}
	~TerminalExpression() = default;

	// Í¨¹ý Expression ¼Ì³Ð
	virtual bool interpret(const std::string & context) override;

private:
	std::string data;
};