#pragma once

#include "Expression.h"

class TerminalExpression : public Expression
{
public:
	TerminalExpression(const std::string &data) : data(data) {}
	~TerminalExpression() = default;

	// ͨ�� Expression �̳�
	virtual bool interpret(const std::string & context) override;

private:
	std::string data;
};