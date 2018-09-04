#pragma once

#include "Strategy.h"

struct OperationAdd : public Strategy
{
	// Í¨¹ý Strategy ¼Ì³Ð
	virtual int doOperation(int num1, int num2) override;
};