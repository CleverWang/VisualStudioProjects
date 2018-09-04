#pragma once

#include "Strategy.h"

struct OperationSubstract : public Strategy
{
	// Í¨¹ý Strategy ¼Ì³Ð
	virtual int doOperation(int num1, int num2) override;
};