#pragma once

#include <string>

struct Expression
{
	virtual bool interpret(const std::string &context) = 0;
	virtual ~Expression() = default;
};