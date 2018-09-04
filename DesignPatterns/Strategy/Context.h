#pragma once

#include "Strategy.h"

class Context
{
public:
	Context(Strategy *strategy) : strategy(strategy) {}
	~Context() { delete strategy; }

	int executeStrategy(int num1, int num2);

private:
	Strategy * strategy;
};