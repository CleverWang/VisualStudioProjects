#pragma once

#include "Strategy.h"

struct OperationSubstract : public Strategy
{
	// ͨ�� Strategy �̳�
	virtual int doOperation(int num1, int num2) override;
};