#pragma once

#include "Strategy.h"

struct OperationAdd : public Strategy
{
	// ͨ�� Strategy �̳�
	virtual int doOperation(int num1, int num2) override;
};