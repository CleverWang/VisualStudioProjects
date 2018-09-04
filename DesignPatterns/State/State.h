#pragma once

#include <string>

class Context;

struct State
{
	virtual void doAction(Context *context) = 0;
	virtual ~State() = default;
	virtual std::string toString() const = 0;
};