#pragma once

#include "Strategy.h"

struct OperationMultiply : public Strategy
{
	// ͨ�� Strategy �̳�
	virtual int doOperation(int num1, int num2) override;
};